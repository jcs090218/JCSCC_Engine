/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Application.h"

#include <iostream>

#include "Mouse.h"
#include "Keyboard.h"

namespace JCS_SDL_Engine
{
    Application::Application()
        // Windows
        : m_pWindow(nullptr)
        , m_windowTitle("SDL_Framework_JCS")
        , m_screenWidth(1280)
        , m_screenHeight(720)
        , m_showFrameRate(false)
        // Client's Socket
        // Game Time
        , m_pTimer(nullptr)
        , m_appPaused(false)
        // Input Handle
        , m_keyEvent()
        , m_pMouse(nullptr)
        , m_pKeyboard(nullptr)
    {
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

        // Main Application Loop
        while (true)
        {
            // Handle Input buffer
            if (SDL_PollEvent(&m_keyEvent))
            {
                
                // Get Current Input Key
                uint32 input = m_keyEvent.type;

                // Check is Exit App
                if (input == SDL_QUIT)
                    break;

                // Handle Game Input
                switch (input)
                {
                case SDL_MOUSEMOTION:
                {
                    m_pMouse->SetMouseCoords(
                        static_cast<float32>(m_keyEvent.motion.x), 
                        static_cast<float32>(m_keyEvent.motion.y));
                } break;
                case SDL_KEYDOWN:
                {
                    m_pKeyboard->pressKey(m_keyEvent.key.keysym.sym);
                } break;
                case SDL_KEYUP:
                {
                    m_pKeyboard->releaseKey(m_keyEvent.key.keysym.sym);
                } break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    m_pKeyboard->pressKey(m_keyEvent.button.button);
                } break;
                case SDL_MOUSEBUTTONUP:
                {
                    m_pKeyboard->pressKey(m_keyEvent.button.button);
                } break;
                }
            }


            // Framerate Calculation
            if (GetShowFrameRate())
                m_pWindow->CalculateFrameStats(GetGameTimer());

            m_pTimer->Tick();

            // Main Game Loop
            if (!GetAppPause())
            {
                RunApp(m_pTimer->DeltaTime());

                m_pWindow->SwapBuffer();
            }
            else
            {
                Sleep(100);
            }

        }
    }

}

