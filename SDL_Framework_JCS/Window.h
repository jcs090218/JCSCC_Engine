/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>

#include <OpenGL_Framework_JCS\OpenGL_StdAfx.h>
#include <SDL_Framework_JCS\SDL_StdAfx.h>

#include <GameTool_JCS\GameTimer.h>

#include <GameInterface_JCS\JCS_Window.h>

namespace JCS_SDL_Engine
{
    class JCS_GameTool::GameTimer;

    enum WindowFlags 
    { 
        INVISIBLE = 0x1, 
        FULLSCREEN = 0x2, 
        BORDERLESS = 0x4 
    };

    class Window 
        : public JCS_GameInterface::JCS_Window
    {
    private:
        SDL_Window* m_pSDLWindow;
        std::string m_windowTitle;
        int m_screenWidth, m_screenHeight;

    public:
        Window();
        virtual ~Window();

        bool Create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

        void SwapBuffer();
        virtual void CalculateFrameStats(JCS_GameTool::GameTimer* pTimer) override;

        // getter
        int GetScreenWidth() const { return this->m_screenWidth; }
        int GetScreenHeight() const { return this->m_screenHeight; }
    };
}

#endif __WINDOW_H__

