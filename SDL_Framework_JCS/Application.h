#ifndef __APPLICATION_H__
/**
 * $File: Application.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __APPLICATION_H__

#include <GameTool_JCS\GameTool_StdAfx.h>
#include <SDL_Framework_JCS\Window.h>


namespace JCS_SDL_Engine
{
    class JCS_GameTool::GameTimer;
    class Mouse;
    class Keyboard;

	//====================================================================================
	// Name : Application 
	//
	// Description : Application Interface for ppl use the SDL 
	// as the application.
	//====================================================================================
    class Application
        : public JCS_Application
    {
    protected:
        JCS_SDL_Engine::Window* m_pWindow;
		std::vector<JCS_SDL_Engine::Window*> m_subWindows;
        int m_screenWidth, m_screenHeight;
        std::string m_windowTitle;

		bool m_allWindowsClosed = false;

		// all window is separate?
		bool m_windowIndependent = false;

        // 遊戲端
        bool m_showFrameRate;

        // 遊戲控制器
        SDL_Event m_event;       // input handle
        Mouse* m_pMouse;
        Keyboard* m_pKeyboard;

        // 遊戲時間
        JCS_GameTool::GameTimer* m_pTimer;
        bool m_appPaused;        // use when we want to stop the game

    public:
        Application();
        virtual ~Application();

        virtual bool Initialize() override;
        void Run();

		/**
		* Create the sub window.
		*
		* for developer who want multiple windows.
		*/
		void CreateSubWindow(
			std::string windowName,
			int32 screenWidth,
			int32 screenHeight,
			uint32 currentFlags);
		void CreateSubWindow(
			std::string windowName,
			int32 screenX,
			int32 screenY,
			int32 screenWidth,
			int32 screenHeight,
			uint32 currentFlags);


		/**
		* Get the window base on the name.
		*/
		JCS_SDL_Engine::Window* GetWindowByName(std::string cmpName) const
		{
			for (JCS_SDL_Engine::Window* pWindow : m_subWindows)
			{
				if (pWindow->IsName(cmpName))
					return pWindow;
			}

			JCS_Debug(L"Failed to get the window by the name. \
				Plz check u enter the right name. Or the window is created?");

			return nullptr;
		}

        /** setter **/
        void ShowFrameRate(const bool showFrameRate) { this->m_showFrameRate = showFrameRate; }
        void SetScreenWidth(const int32 screenWidth) { this->m_screenWidth = screenWidth; }
        void SetScreenHeight(const int32 screenHeight){ this->m_screenHeight = screenHeight; }
        void SetWindowTitle(const std::string windowTitle) { this->m_windowTitle = windowTitle; }
		void SetWindowIndependent(const bool act) { this->m_windowIndependent = act; }

        /** getter **/
        bool GetAppPause() const { return this->m_appPaused; }
		JCS_SDL_Engine::Window* GetMainWindow() const { return this->m_pWindow; }
		JCS_SDL_Engine::Window* GetSubWindowAt(const int index) const { return this->m_subWindows.at(index); }
        JCS_GameTool::GameTimer* GetGameTimer() const { return this->m_pTimer; }
		bool GetWindowIndependent() const { return this->m_windowIndependent; }

        Mouse* GetMousePtr() const { return this->m_pMouse; }
        Mouse& GetMouseRef() const { return *(this->m_pMouse); }
        Keyboard* GetKeyboardPtr() const { return this->m_pKeyboard; }
        Keyboard& GetKeyboardRef() const { return *(this->m_pKeyboard); }

    private:
        bool GetShowFrameRate() const { return this->m_showFrameRate; }

		/**
		* Swap the buffer dealing with multiple window.
		*/
		void SwapBuffer();

		/**
		* Weather do the frame rate calculation?
		*/
		void FramerateCalculation();

		/**
		* Handle input event.
		*/
		void HandleEvent(SDL_Event& evt);

		/**
		* Begin render the frame.
		*/
		void BeginRender();
		/**
		* End render the frame.
		*/
		void EndRender();

		/**
		* Check if all window close?
		*/
		void CheckAllWindowClosed();

		/**
		* Close all the window.
		*/
		void FreeAllWindow();

		/**
		* Handle the global input.
		*/
		void GlobalHandleEvent(SDL_Event& evt);

		/**
		* Clean input buffer.
		*/
		void InputUpdate();

    protected:
        // Run Main App here
        virtual void RunApp(float32 deltaTime) = 0;
    };

}

#endif // __APPLICATION_H__

