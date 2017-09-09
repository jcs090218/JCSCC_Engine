/**
 * $File: Application.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "Application.h"

#include <iostream>

#include "Mouse.h"
#include "Keyboard.h"


namespace JCS_SDL_Engine
{

	Application::Application()
		// Windows
		: m_pWindow(nullptr)
		, m_subWindows()
		, m_windowTitle("SDL_Framework_JCS")
		, m_screenWidth(1280)
		, m_screenHeight(720)
		, m_showFrameRate(false)
		// Client's Socket
		// Game Time
		, m_pTimer(nullptr)
		, m_appPaused(false)
		// Input Handle
		, m_event()
		, m_pMouse(nullptr)
		, m_pKeyboard(nullptr)
	{
		// create the main window pointer.
		m_pWindow = new Window();

		m_pTimer = new JCS_GameTool::GameTimer();        // 建立遊戲時間

		m_pMouse = new Mouse();
		m_pKeyboard = new Keyboard();
	}

	Application::~Application()
	{
		SafeDeleteObject(m_pMouse);
		SafeDeleteObject(m_pKeyboard);
		SafeDeleteObject(m_pTimer);
		SafeDeleteObject(m_pWindow);
		SafeDeleteContainerPtrObject
			<std::vector<JCS_SDL_Engine::Window*>,
			Window>(m_subWindows);
	}

	bool Application::Initialize()
	{
		// Create Window
		if (!m_pWindow->Create(m_windowTitle, m_screenWidth, m_screenHeight, JCS_SDL_Engine::FULLSCREEN))
			return false;

		// success to inital everthing
		return true;
	}

	void Application::Run()
	{
		m_pTimer->Reset();

		bool quit = false;

		// Main Application Loop
		while (!m_allWindowsClosed && !quit)
		{
			// Handle Input buffer
			while (SDL_PollEvent(&m_event) != 0)
			{
				// Multiple Window event handle.
				// SOURCE(jenchieh): http://lazyfoo.net/tutorials/SDL/36_multiple_windows/index.php
				HandleEvent(m_event);

				GlobalHandleEvent(m_event);

				// Get Current Input Key
				uint32 input = m_event.type;

				// if window are not separate mode.
				// check the root window info.
				if (!GetWindowIndependent())
				{
					// Check is Exit App
					if (input == SDL_QUIT || !m_pWindow->isShown())
						quit = true;
				}
			}

			// Framerate Calculation
			FramerateCalculation();

			// do timer tick.
			m_pTimer->Tick();

			// Main Game Loop
			if (!GetAppPause())
			{
				BeginRender();
				//----------------------------

				RunApp(m_pTimer->DeltaTime());

				//----------------------------
				EndRender();
				SwapBuffer();
			}
			else
			{
				// else delay the thread.
				Sleep(100);
			}

			// check all window close?
			CheckAllWindowClosed();

			InputUpdate();
		}

		// free all window
		FreeAllWindow();

		// Don't forget to quit SDL.
		SDL_Quit();
	}

	void Application::CreateSubWindow(
		std::string windowName, 
		int32 screenWidth, 
		int32 screenHeight, 
		uint32 currentFlags)
	{
		// create one window.
		JCS_SDL_Engine::Window* pWindow = new JCS_SDL_Engine::Window();

		pWindow->Create(
			windowName, 
			screenWidth, 
			screenHeight, 
			currentFlags);

		// add it into array.
		m_subWindows.push_back(pWindow);
	}

	void Application::CreateSubWindow(
		std::string windowName,
		int32 screenX,
		int32 screenY,
		int32 screenWidth,
		int32 screenHeight,
		uint32 currentFlags)
	{
		// create one window.
		JCS_SDL_Engine::Window* pWindow = new JCS_SDL_Engine::Window();

		pWindow->Create(
			windowName, 
			screenX, 
			screenY, 
			screenWidth, 
			screenHeight, 
			currentFlags);

		// add it into array.
		m_subWindows.push_back(pWindow);
	}

	void Application::SwapBuffer()
	{
		m_pWindow->SwapBuffer();

		// swap buffer with all open window.
		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->SwapBuffer();
		}
	}

	void Application::FramerateCalculation()
	{
		// check if the trigger is on?
		if (!GetShowFrameRate())
			return;

		// calculate the main window.
		m_pWindow->CalculateFrameStats(GetGameTimer());

		// calculate the sub window.
		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->CalculateFrameStats(GetGameTimer());
		}
	}

	void Application::HandleEvent(SDL_Event& evt)
	{
		m_pWindow->HandleEvent(evt);

		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->HandleEvent(evt);
		}
	}

	void Application::BeginRender()
	{
		m_pWindow->BeginRender();

		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->BeginRender();
		}
	}

	void Application::EndRender()
	{
		m_pWindow->EndRender();

		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->EndRender();
		}
	}

	void Application::CheckAllWindowClosed()
	{
		// first turn of trigger.
		m_allWindowsClosed = true;

		// if main window still remain, return it.
		if (m_pWindow->isShown())
		{
			m_allWindowsClosed = false;
			return;
		}

		// loop through all window and check if any window 
		// still open?
		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			if (pWindow->isShown())
			{
				// some window still open.
				m_allWindowsClosed = false;
				break;
			}
		}
	}

	void Application::FreeAllWindow()
	{
		m_pWindow->Free();

		// loop through all window and check if any window 
		// still open?
		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->Free();
		}
	}

	void Application::GlobalHandleEvent(SDL_Event& evt)
	{
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
		}
	}

	void Application::InputUpdate()
	{
		// global.
		m_pKeyboard->update();

		// main windows
		m_pWindow->Update();

		// sub windows
		for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
		{
			pWindow->Update();
		}
	}

}

