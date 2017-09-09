#ifndef __WINDOW_H__
/**
 * $File: Window.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __WINDOW_H__

#include <string>

#include <OpenGL_Framework_JCS\OpenGL_StdAfx.h>
#include <SDL_Framework_JCS\SDL_StdAfx.h>

#include <GameTool_JCS\GameTimer.h>

#include <GameInterface_JCS\JCS_Window.h>

namespace JCS_SDL_Engine
{
    class JCS_GameTool::GameTimer;
	class Mouse;
	class Keyboard;

    enum WindowFlags 
    { 
        INVISIBLE = 0x1, 
        FULLSCREEN = 0x2, 
        BORDERLESS = 0x4 
    };

	//====================================================================================
	// Name : Window 
	//
	// Description : Handle Window info related buffer.
	//====================================================================================
    class Window 
        : public JCS_GameInterface::JCS_Window
    {
    private:
        SDL_Window* m_pSDLWindow = nullptr;
		SDL_Renderer* m_pRenderer = nullptr;

		Mouse* m_pMouse = nullptr;
		Keyboard* m_pKeyboard = nullptr;

		int32 m_windowID = -1;
        std::string m_windowTitle;
		int32 m_screenWidth = 0;
		int32 m_screenHeight = 0;
		int32 m_screenX = 0;
		int32 m_screenY = 0;

		int32 m_frameCnt = 0;
		float32 m_timeElapsed = 0.0f;

		bool m_shown = false;
		bool m_minimized = false;;

		bool m_mouseFocus = false;
		bool m_keyboardFocus = false;

    public:
        Window();
        virtual ~Window();

        bool Create(
			std::string windowName, 
			int32 screenWidth, 
			int32 screenHeight, 
			uint32 currentFlags);
		bool Create(
			std::string windowName,
			int32 screenX,
			int32 screenY,
			int32 screenWidth,
			int32 screenHeight,
			uint32 currentFlags);

        void SwapBuffer();
        virtual void CalculateFrameStats(JCS_GameTool::GameTimer* pTimer) override;

		void Update();

		/**
		* Focus this window?
		*/
		void Focus();
		/**
		* Input message?
		*/
		void HandleEvent(SDL_Event& e);
		/**
		* Free all COM.
		*/
		void Free();
		/**
		* Render using SDL engine.
		*/
		void BeginRender();
		/**
		* Call this when the last frame.
		*/
		void EndRender();

		/**
		* Check the window name?
		*/
		bool IsName(std::string cmpName)
		{
			return (cmpName == m_windowTitle);
		}

		/** setter **/

        /** getter **/
        int32 GetScreenWidth() const { return this->m_screenWidth; }
        int32 GetScreenHeight() const { return this->m_screenHeight; }
		bool isShown() const { return this->m_shown; }
		bool isMouseFocus() const { return this->m_mouseFocus; }
		bool isKeyboardFocus() const { return this->m_keyboardFocus; }
		bool isMinimized() const { return this->m_minimized; }
		int32 WindowID() const { return this->m_windowID; }
		std::string GetWindowTitle() { return this->m_windowTitle; }

		Mouse* GetMousePtr() const { return this->m_pMouse; }
		Keyboard* GetKeyboardPtr() const { return this->m_pKeyboard; }
    };
}

#endif __WINDOW_H__

