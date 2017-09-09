/**
 * $File: Window.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "Window.h"

#include "JCS_Errors.h"

#include "SDL\include\SDL_image.h"
#include "SDL\include\SDL_ttf.h"

#include "Mouse.h"
#include "Keyboard.h"


namespace JCS_SDL_Engine
{

	Window::Window()
		: m_pSDLWindow(nullptr)
		, m_screenWidth(1024)
		, m_screenHeight(768)
		, m_windowTitle()
		, m_shown(false)
		// Input Handle
		, m_pMouse(nullptr)
		, m_pKeyboard(nullptr)
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		m_pMouse = new Mouse();
		m_pKeyboard = new Keyboard();
	}

	Window::~Window()
	{
		SafeDeleteObject(m_pMouse);
		SafeDeleteObject(m_pKeyboard);
	}

	bool Window::Create(
		std::string windowName,
		int32 screenWidth,
		int32 screenHeight,
		uint32 currentFlags)
	{
		return Create(
			windowName, 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			screenWidth, 
			screenHeight, 
			currentFlags);
	}

	bool Window::Create(
		std::string windowName, 
		int32 screenX,
		int32 screenY,
		int32 screenWidth, 
		int32 screenHeight, 
		uint32 currentFlags)
	{
		Uint32 flags = SDL_WINDOW_OPENGL;

		if (currentFlags & INVISIBLE)
			flags |= SDL_WINDOW_HIDDEN;
		if (currentFlags & FULLSCREEN)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		if (currentFlags & BORDERLESS)
			flags |= SDL_WINDOW_BORDERLESS;

		// Open an SDL window
		m_pSDLWindow = SDL_CreateWindow(
			windowName.c_str(), 
			screenX,
			screenY,
			screenWidth, 
			screenHeight, 
			SDL_WINDOW_OPENGL);

		// check if create success.
		if (!m_pSDLWindow)
		{
			fatalError("SDL Window could not be created!");
			return false;
		}

		this->m_windowTitle = windowName;

		this->m_screenX = screenX;
		this->m_screenY = screenY;
		this->m_screenWidth = screenWidth;
		this->m_screenHeight = screenHeight;

		this->m_mouseFocus = true;
		this->m_keyboardFocus = true;

		// Create renderer for each window
		m_pRenderer = SDL_CreateRenderer(m_pSDLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!m_pRenderer)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			SDL_DestroyWindow(m_pSDLWindow);
			m_pSDLWindow = nullptr;

			return false;
		}

		// Initialize renderer color
		SDL_SetRenderDrawColor(m_pRenderer, 0x00, 0x00, 0x00, 0xFF);

		// Grab window identifier
		m_windowID = SDL_GetWindowID(m_pSDLWindow);

		// Flag as opened
		m_shown = true;

		// Set up our OpenGL context
		SDL_GLContext glContext = SDL_GL_CreateContext(m_pSDLWindow);
		if (!glContext)
		{
			fatalError("SDL_GL context could not be created!");
			return false;
		}

		// Set up glew (optional but recommended)
		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			fatalError("Could not initialize glew!");
			return false;
		}

		// Check the OpenGL version
		std::printf("***    OpenGL Version: %s    ***\n", glGetString(GL_VERSION));

		// Set the background color to black
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// Set Vertical Sync
		SDL_GL_SetSwapInterval(1);        // 0: disable V-Sync, 1: enable V-Sync

		// Enable alpha blend
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;
	}

	void Window::Update()
	{
		GetKeyboardPtr()->update();
	}

	void Window::SwapBuffer()
	{
		//Swap our buffer and draw everything to the screen!
		SDL_GL_SwapWindow(m_pSDLWindow);
	}

	void Window::CalculateFrameStats(JCS_GameTool::GameTimer* pTimer)
	{
		++m_frameCnt;

		if ((pTimer->TotalTime() - m_timeElapsed) >= 1.0f)
		{
			float fps = static_cast<float>(m_frameCnt); // fps = frameCnt / 1
			float mspf = 1000.0f / fps;

			std::stringstream m_timeText;
			m_timeText.precision(6);
			m_timeText << m_windowTitle << "    "
				<< "FPS: " << fps << "    "
				<< "Frame Time: " << mspf << " (ms)";

			//Set text to be rendered
			SDL_SetWindowTitle(m_pSDLWindow, m_timeText.str().c_str());

			m_frameCnt = 0;
			m_timeElapsed += 1.0f;
		}
	}

	void Window::Focus()
	{
		// Restore window if needed
		if (!m_shown)
		{
			SDL_ShowWindow(m_pSDLWindow);
		}

		// Move window forward
		SDL_RaiseWindow(m_pSDLWindow);
	}

	void Window::HandleEvent(SDL_Event& evt)
	{
		// check window id.
		if (evt.window.windowID != m_windowID)
			return;

		// If an event was detected for this window
		if (evt.type == SDL_WINDOWEVENT)
		{
			//Caption update flag
			bool updateCaption = false;

			switch (evt.window.event)
			{
			// Window appeared
			case SDL_WINDOWEVENT_SHOWN:
			{
				m_shown = true;
			}
			break;
			// Window disappeared
			case SDL_WINDOWEVENT_HIDDEN:
			{
				m_shown = false;
			}
			break;
			// Get new dimensions and repaint
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			{
				m_screenWidth = evt.window.data1;
				m_screenHeight = evt.window.data2;
				SDL_RenderPresent(m_pRenderer);
			}
			break;
			// Repaint on expose
			case SDL_WINDOWEVENT_EXPOSED:
			{
				SDL_RenderPresent(m_pRenderer);
			}
			break;
			// Mouse enter
			case SDL_WINDOWEVENT_ENTER:
			{
				m_mouseFocus = true;
				updateCaption = true;
			}
			break;
			// Mouse exit
			case SDL_WINDOWEVENT_LEAVE:
			{
				m_mouseFocus = false;
				updateCaption = true;
			}
			break;
			// Keyboard focus gained
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			{
				m_keyboardFocus = true;
				updateCaption = true;
			}
			break;
			// Keyboard focus lost
			case SDL_WINDOWEVENT_FOCUS_LOST:
			{
				m_keyboardFocus = false;
				updateCaption = true;
			}
			break;
			// Window minimized
			case SDL_WINDOWEVENT_MINIMIZED:
			{
				m_minimized = true;
			}
			break;
			// Window maxized
			case SDL_WINDOWEVENT_MAXIMIZED:
			{
				m_minimized = false;
			}
			break;
			// Window restored
			case SDL_WINDOWEVENT_RESTORED:
			{
				m_minimized = false;
			}
			break;
			// Hide on close
			case SDL_WINDOWEVENT_CLOSE:
			{
				SDL_HideWindow(m_pSDLWindow);
			}
			break;
			} // end switch(evt.window.event)


			// Update window caption with new data
			if (updateCaption)
			{
				std::stringstream caption;
				caption << "SDL Tutorial - ID: " << m_windowID << " MouseFocus:" << ((m_mouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((m_keyboardFocus) ? "On" : "Off");
				SDL_SetWindowTitle(m_pSDLWindow, caption.str().c_str());
			}
		}


		// Get Current Input Key
		uint32 input = evt.type;

		// Handle Game Input
		switch (input)
		{
		case SDL_MOUSEMOTION:
		{
			m_pMouse->SetMouseCoords(
				static_cast<float32>(evt.motion.x),
				static_cast<float32>(evt.motion.y));
		}
		break;
		case SDL_MOUSEBUTTONDOWN:
		{
			m_pMouse->SetMouseButtonDown(true);
			m_pMouse->SetMouseButton(true);
		}
		break;
		case SDL_MOUSEBUTTONUP:
		{
			m_pMouse->SetMouseButtonUp(true);
			m_pMouse->SetMouseButton(false);
		}
		break;
		case SDL_KEYDOWN:
		{
			m_pKeyboard->KeysPressedThisFrame(evt.key.keysym.sym, true);
			m_pKeyboard->KeyDownThisFrame(evt.key.keysym.sym, true);
		}
		break;
		case SDL_KEYUP:
		{
			m_pKeyboard->KeysReleasedThisFrame(evt.key.keysym.sym, true);
			m_pKeyboard->KeyDownThisFrame(evt.key.keysym.sym, false);
		}
		break;
		} // end switch(input)
	}

	void Window::BeginRender()
	{
		if (m_minimized)
			return;

		//Clear screen
		SDL_SetRenderDrawColor(m_pRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(m_pRenderer);
	}

	void Window::EndRender()
	{
		if (m_minimized)
			return;

		//Update screen
		SDL_RenderPresent(m_pRenderer);
	}

	void Window::Free()
	{
		if (m_pSDLWindow)
		{
			SDL_DestroyWindow(m_pSDLWindow);
		}

		m_mouseFocus = false;
		m_keyboardFocus = false;
		m_screenWidth = 0;
		m_screenHeight = 0;
	}

}

