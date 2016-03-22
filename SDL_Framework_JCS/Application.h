#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <GameTool_JCS\GameTool_StdAfx.h>
#include <SDL_Framework_JCS\Window.h>

namespace JCS_SDL_Engine
{
    class JCS_GameTool::GameTimer;
    class Mouse;
    class Keyboard;

    class Application
        : public JCS_Application
    {
    protected:
        JCS_SDL_Engine::Window* m_pWindow;
        int m_screenWidth, m_screenHeight;
        std::string m_windowTitle;

        // 遊戲端
        bool m_showFrameRate;

        // 遊戲控制器
        SDL_Event m_keyEvent;       // input handle
        Mouse* m_pMouse;
        Keyboard* m_pKeyboard;

        // 遊戲時間
        JCS_GameTool::GameTimer* m_pTimer;
        bool m_appPaused;		// use when we want to stop the game

    public:
        Application();
        virtual ~Application();

        virtual bool Initialize() override;
        void Run();

        // setter
        void ShowFrameRate(const bool showFrameRate) { this->m_showFrameRate = showFrameRate; }
        void SetScreenWidth(const int32 screenWidth) { this->m_screenWidth = screenWidth; }
        void SetScreenHeight(const int32 screenHeight){ this->m_screenHeight = screenHeight; }
        void SetWindowTitle(const std::string windowTitle){ this->m_windowTitle = windowTitle; }

        // getter
        bool GetAppPause() const { return this->m_appPaused; }
        JCS_GameTool::GameTimer* GetGameTimer() const { return this->m_pTimer; }

        Mouse* GetMousePtr() const { return this->m_pMouse; }
        Mouse& GetMouseRef() const { return *(this->m_pMouse); }
        Keyboard* GetKeyboardPtr() const { return this->m_pKeyboard; }
        Keyboard& GetKeyboardRef() const { return *(this->m_pKeyboard); }

    private:
        bool GetShowFrameRate() const { return this->m_showFrameRate; }

    protected:
        // Run Main App here
        virtual void RunApp(float32 gameTime) = 0;
    };

}

#endif // __APPLICATION_H__

