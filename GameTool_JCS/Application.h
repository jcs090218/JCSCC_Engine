#ifndef __APPLICATION_H__
/**
 * $File: Application.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __APPLICATION_H__


#include <Socket_Framework_JCS\Winsock2_Socket.h>

#include "Window.h"

#include <GameInput_JCS\PlatformType.h>


#undef SetPort


namespace JCS_GameTool
{
    class GameTimer;

    //====================================================================================
    // Class Name : Application 
    //
    // Description : Handle the Application Layer, so the programmer 
    // can easily modified the application by just passing through 
    // provided functions call.
    //====================================================================================
    class Application 
        : public JCS_Application
    {
    private:
        // Main Variables
        Window* m_pWindow;      // window itself
		std::vector<Window*> m_subWindows;

		// components.
		std::wstring m_windowTitle;     // title of this application.
        int32 m_screenWidth, m_screenHeight;        // screen width and height

		std::wstring m_windowClass;     // window class

        // "Micosoft Window"'s Components
        HINSTANCE m_hInstance, m_hPrevInstance;
        LPSTR m_lpCmdLine;      // command line of the window (application layer)
        int32 m_nCmdShow;       // command line of the window (application layer)

        HWND m_mainWindow;	// window handle

        MSG m_message;  // window message

        // 遊戲端
        bool m_showFrameRate;       // frame rate count.

        // 遊戲平台 (Game Platform)
        JCS_GameInput::PlatformType m_platformType;         // Device which platform is the game developing to?
        JCS_GameInterface::JCS_Input* m_pPlatformInput;     // what kind of input is supported to this application?

        // 客戶端Socket
        JCS_Network::WinSock2_Socket* m_pSocket;
        char* m_hostname;           // online game need the ip address
        uint32 m_port;              // online game need this port number.
        bool m_isOnlineGame;        // boolean to check this application an online game?

        // 遊戲時間 (Game Time)
        JCS_GameTool::GameTimer* m_pTimer;      // timer for the application.
        bool m_appPaused;        // use when we want to stop the game


    public:
        Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow);
        virtual ~Application();

        virtual bool Initialize() override;
        uint32 Run();

		/**
		* Create the sub window.
		*
		* for developer who want multiple windows.
		*/
		void CreateSubWindow(
			std::wstring windowTitle,
			int32 x,
			int32 y,
			int32 width,
			int32 height);
		void CreateSubWindow(
			std::wstring windowTitle,
			int32 width,
			int32 height);

		/**
		* Get the window base on the name/window title.
		*/
		Window* GetWindowByName(std::wstring cmpName) const
		{
			for (Window* pWindow : m_subWindows)
			{
				if (pWindow->IsName(cmpName))
					return pWindow;
			}

			JCS_Debug(L"Failed to get the window by the name. \
				Plz check u enter the right name. Or the window is created?");

			return nullptr;
		}

        // -- setter
        /** Weather u want to show FPS in application. */
        void ShowFrameRate(const bool showFrameRate) { this->m_showFrameRate = showFrameRate; }
        /** Screen Width of this application */
        void SetScreenWidth(const int32 screenWidth) { this->m_screenWidth = screenWidth; }
        /** Screen Height of this application. */
        void SetScreenHeight(const int32 screenHeight){ this->m_screenHeight = screenHeight; }
        /** Title of this application. */
        void SetWindowTitle(const std::wstring windowTitle){ this->m_windowTitle = windowTitle; }
        /**  Host Name/IP Address from the server. */
        void SetHostName(char* hostname) { this->m_hostname = hostname; }
        /** port of the packet receive from. */
        void SetPort(const uint32 port) { this->m_port = port; }
        /** Check if the application going to use OS/Network Layer. */
        void SetIsOnlineGame(const bool isOnlineGame) { this->m_isOnlineGame = isOnlineGame; }
        /** pause the game? */
        void SetAppPause(const bool pause) { this->m_appPaused = pause; }
        /** Set the inside icon? */
        void SetIcon(const uint32 icon) { this->m_pWindow->SetIcon(icon); }
        /** Set the outside icon? */
        void SetExeIcon(const uint32 icon) { this->m_pWindow->SetExeIcon(icon); }

        // -- getter
        // Window
        /** Return the window main */
        Window* GetWindow() const { return this->m_pWindow; }
        /** Return Windows OS object */
        HWND GetMainWindow() { return this->m_mainWindow; }
        /** Return Icon in this application. */
        uint32 GetIcon() const { return this->m_pWindow->GetIcon(); }
        /** Return External-Icon in this application */
        uint32 GetExeIcon() const { return this->m_pWindow->GetExeIcon(); }

        // Game Platform
        /** Set the platform type of this application going to be build on. */
        void SetPlatformType(const PlatformType type) { this->m_platformType = type; }
        /** Return the enum type of the platform type. */
        PlatformType GetPlatformType() const { return this->m_platformType; }
        /** Return Platform Input object by pointer. */
        JCS_Input* GetPlatformInputAsPtr() const { return this->m_pPlatformInput; }
        /** Return Platform Input object by references. */
        JCS_Input& GetPlatformInputAsRef() const { return *(this->m_pPlatformInput); }
        /** Return the current keyboard device layer. */
        JCS_GameInput::KeyboardServer* GetKeyBoardServer() { return m_pWindow->GetKeyboardServer(); };
        /** Return the current mouse device layer. */
        JCS_GameInput::MouseServer* GetMouseServer() { return m_pWindow->GetMouseServer(); }

        // Game Socket
        /** Get the connection from the winsock */
        JCS_Network::WinSock2_Socket* getConnection() const { return m_pSocket; }
        /** Check if this application using OS/Network layer? Online Game? */
        bool GetIsOnlineGame() const { return this->m_isOnlineGame; }

        // Game Timer
        /** Is the game pasue? */
        bool GetAppPause() const { return this->m_appPaused; }
        /** Get Game Timer by pointer. */
        JCS_GameTool::GameTimer* GetGameTimer() const { return this->m_pTimer; }

    private:
        /** get FPS count */
        bool GetShowFrameRate() const { return this->m_showFrameRate; }
        /**  
            Setup the input type, so application can run on 
            different OS/platform.
        */
        void RunPlatformContoller();

		/**
		* Weather do the frame rate calculation?
		*/
		void FramerateCalculation();

    protected:
        /**
            Initialize the network layer.
        */
        bool InitSocket();        // Create GameSocket

        /**  
            Initialize the window and create the window
        */
        bool InitWindow();        // Create GameWindow

        /**  
            Initialize the platform layer.
        */
        bool InitPlatform();    // Create what kind of platform the game will belong to

		/**
			Check if the client connect to the server.

			@return true: connected.
			@return false: not connected.
		*/
		bool IsServerConnect();

        /**
            Override this enable to run the game
        */
        virtual void RunApp(float32 deltaTime) = 0;

    };

} // end namespace "JCS_GameTool"

typedef JCS_GameTool::Application Application;

#endif // __APPLICATION_H__
