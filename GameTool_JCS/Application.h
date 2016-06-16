/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __APPLICATION_H__
#define __APPLICATION_H__


#include <Socket_Framework_JCS\Winsock2_Socket.h>

#include <GameInput_JCS\DirectInput\Keyboard.h>
#include <GameInput_JCS\DirectInput\Mouse.h>

#include <GameInput_JCS\PlatformType.h>

#undef SetPort

namespace JCS_GameTool
{
    class Window;
    class GameTimer;

    //------------------------------------------------------------------------------------
    // Name : Application 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class Application 
        : public JCS_Application
    {
    private:
        // Main Variables
        Window* m_pWindow;
        std::wstring m_windowTitle;
        std::wstring m_windowClass;
        int32 m_screenWidth, m_screenHeight;
        uint32 m_icon, m_exeIcon;

        // "Micosoft Window"'s Components
        HINSTANCE m_hInstance, m_hPrevInstance;
        LPSTR m_lpCmdLine;
        int32 m_nCmdShow;

        HWND m_mainWindow; // window handle

        MSG m_message;  // window message

        // 遊戲端
        bool m_showFrameRate;

        // 遊戲平台 (Game Platform)
        JCS_GameInput::PlatformType m_platformType;
        JCS_GameInterface::JCS_Input* m_pPlatformInput;
        static JCS_GameInput::KeyboardServer* s_pKeyBoardServer;
        static JCS_GameInput::MouseServer* s_pMouseServer;

        // 客戶端Socket
        JCS_Network::WinSock2_Socket* m_pSocket;
        char* m_hostname;
        uint32 m_port;
        bool m_isOnlineGame;

        // 遊戲時間 (Game Time)
        JCS_GameTool::GameTimer* m_pTimer;
        bool m_appPaused;        // use when we want to stop the game


    public:
        Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow);
        virtual ~Application();

        virtual bool Initialize() override;
        uint32 Run();

        // -- setter
        void ShowFrameRate(const bool showFrameRate) { this->m_showFrameRate = showFrameRate; }
        void SetScreenWidth(const int32 screenWidth) { this->m_screenWidth = screenWidth; }
        void SetScreenHeight(const int32 screenHeight){ this->m_screenHeight = screenHeight; }
        void SetWindowTitle(const std::wstring windowTitle){ this->m_windowTitle = windowTitle; }
        void SetHostName(char* hostname) { this->m_hostname = hostname; }
        void SetPort(const uint32 port) { this->m_port = port; }
        void SetIsOnlineGame(const bool isOnlineGame) { this->m_isOnlineGame = isOnlineGame; }
        void SetAppPause(const bool pause) { this->m_appPaused = pause; }
        void SetIcon(const uint32 icon) { this->m_icon = icon; }
        void SetExeIcon(const uint32 icon) { this->m_exeIcon = icon; }

        // -- getter
        // Window
        Window* GetWindow() const { return this->m_pWindow; }
        HWND GetMainWindow() { return this->m_mainWindow; }
        uint32 GetIcon() const { return this->m_icon; }
        uint32 GetExeIcon() const { return this->m_exeIcon; }

        // Game Platform
        void SetPlatformType(const PlatformType type) { this->m_platformType = type; }
        PlatformType GetPlatformType() const { return this->m_platformType; }
        JCS_Input* GetPlatformInputAsPtr() const { return this->m_pPlatformInput; }
        JCS_Input& GetPlatformInputAsRef() const { return *(this->m_pPlatformInput); }
        static JCS_GameInput::KeyboardServer* GetKeyBoardServer() { return s_pKeyBoardServer; };
        static JCS_GameInput::MouseServer* GetMouseServer() { return s_pMouseServer; }

        // Game Socket
        JCS_Network::WinSock2_Socket* getConnection() const { return m_pSocket; }
        bool GetIsOnlineGame() const { return this->m_isOnlineGame; }

        // Game Timer
        bool GetAppPause() const { return this->m_appPaused; }
        JCS_GameTool::GameTimer* GetGameTimer() const { return this->m_pTimer; }

    private:
        bool GetShowFrameRate() const { return this->m_showFrameRate; }
        void RunPlatformContoller();

    protected:
        bool InitSocket();        // Create GameSocket
        bool InitWindow();        // Create GameWindow
        bool InitPlatform();    // Create what kind of platform the game will belong to

        // Override this enable to run the game
        virtual void RunApp(float32 deltaTime) = 0;

    };

} // end namespace "JCS_GameTool"

typedef JCS_GameTool::Application Application;

#endif // __APPLICATION_H__

