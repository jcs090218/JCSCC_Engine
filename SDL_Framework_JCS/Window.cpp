/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Window.h"

#include "JCS_Errors.h"

#include "SDL\include\SDL_image.h"
#include "SDL\include\SDL_ttf.h"


namespace JCS_SDL_Engine
{
    Window::Window()
        : m_pSDLWindow(nullptr)
        , m_screenWidth(1024)
        , m_screenHeight(768)
        , m_windowTitle()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    }

    Window::~Window()
    {

    }

    bool Window::Create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
    {
        m_windowTitle = windowName;

        m_screenWidth = screenWidth;
        m_screenHeight = screenHeight;

        Uint32 flags = SDL_WINDOW_OPENGL;

        if (currentFlags & INVISIBLE) {
            flags |= SDL_WINDOW_HIDDEN;
        }
        if (currentFlags & FULLSCREEN) {
            flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }
        if (currentFlags & BORDERLESS) {
            flags |= SDL_WINDOW_BORDERLESS;
        }

        //Open an SDL window
        m_pSDLWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
        if (m_pSDLWindow == nullptr) {
            fatalError("SDL Window could not be created!");
            return false;
        }

        //Set up our OpenGL context
        SDL_GLContext glContext = SDL_GL_CreateContext(m_pSDLWindow);
        if (glContext == nullptr) {
            fatalError("SDL_GL context could not be created!");
            return false;
        }

        //Set up glew (optional but recommended)
        GLenum error = glewInit();
        if (error != GLEW_OK) {
            fatalError("Could not initialize glew!");
            return false;
        }

        // Check the OpenGL version
        std::printf("***    OpenGL Version: %s    ***\n", glGetString(GL_VERSION));

        //Set the background color to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // Set Vertical Sync
        SDL_GL_SetSwapInterval(1);        // 0: disable V-Sync, 1: enable V-Sync

        // Enable alpha blend
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }
    
    void Window::SwapBuffer()
    {
        //Swap our buffer and draw everything to the screen!
        SDL_GL_SwapWindow(m_pSDLWindow);
    }

    void Window::CalculateFrameStats(JCS_GameTool::GameTimer* pTimer)
    {
        static int frameCnt = 0;
        static float timeElapsed = 0.0f;

        ++frameCnt;

        if ((pTimer->TotalTime() - timeElapsed) >= 1.0f)
        {
            float fps = static_cast<float>(frameCnt); // fps = frameCnt / 1
            float mspf = 1000.0f / fps;

            std::stringstream m_timeText;
            m_timeText.precision(6);
            m_timeText << m_windowTitle << "    "
                << "FPS: " << fps << "    "
                << "Frame Time: " << mspf << " (ms)";

            //Set text to be rendered
            SDL_SetWindowTitle(m_pSDLWindow, m_timeText.str().c_str());

            frameCnt = 0;
            timeElapsed += 1.0f;
        }
    }

}

