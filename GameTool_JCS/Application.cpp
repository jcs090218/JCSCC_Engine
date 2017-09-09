/**
 * $File: Application.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Application.h"

// Input Devices
#include "GameTimer.h"

#include <GameInput_JCS\PlatformInputFactory.h>
#include <GameInput_JCS\XInput\GamePad.h>


namespace JCS_GameTool
{

    Application::Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow)
        : m_hInstance(hInstance)
        , m_hPrevInstance(hPrevInstance)
        , m_lpCmdLine(lpCmdLine)
        , m_nCmdShow(nCmdShow)
        // Windows
        , m_pWindow(nullptr)
		, m_subWindows()
        , m_mainWindow()
        , m_message()
        , m_windowTitle(L"D3DVS2013_Framework_JCS")
        , m_windowClass(L"Framework Development Class")
        , m_screenWidth(1280)        // default SCREEN WIDTH
        , m_screenHeight(720)        // default SCREEN HEIGHT
        , m_showFrameRate(false)
        // 客戶端Socket
        , m_pSocket(nullptr)
        , m_hostname("127.0.0.1")    // default HOSTNAME
        , m_port(5555)                // default PORT
        , m_isOnlineGame(false)
        // 遊戲時間 (Game Time)
        , m_pTimer(nullptr)
        , m_appPaused(false)
        // 遊戲平台 (Game Platform)
        , m_platformType(PlatformType::PC)
        , m_pPlatformInput(nullptr)
    { 
        // Create Objects
        m_pWindow = new Window(m_mainWindow);

        m_pSocket = new JCS_Network::WinSock2_Socket();        // 建立客戶端Socket
        m_pTimer = new JCS_GameTool::GameTimer();        // 建立遊戲時間
    }


    Application::~Application()
    {
        // Time
        SafeDeleteObject(m_pTimer);

        // Platform
        SafeDeleteObject(m_pPlatformInput);

        // Window
        SafeDeleteObject(m_pWindow);

        // Network
        SafeDeleteObject(m_pSocket);

		// delete all the sub windows
		SafeDeleteContainerPtrObject<std::vector<Window*>, Window>(m_subWindows);
    }

    //====================================================================================--------------------------------------------------------
    // 預設是創建"連線"和"視窗"初始化
    //====================================================================================--------------------------------------------------------
    bool Application::Initialize()
    {

        if (GetIsOnlineGame())
        {
            // 創建連線...
            if (!InitSocket())
            {
                //MessageBox(NULL, L"Socket does not create correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
                return false;
            }
        }

        // Create Platorm
        if (!InitPlatform())
        {
            //MessageBox(NULL, L"Platform does not create correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
            return false;
        }

        // 檢查視窗初始化...
        if (!InitWindow())
        {
            //MessageBox(NULL, L"Window does not create correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
            return false;
        }

        return true;
    }

    //====================================================================================--------------------------------------------------------
    // Program Main Loop
    //====================================================================================--------------------------------------------------------
    uint32 Application::Run()
    {
        GetGameTimer()->Reset();

		bool quit = false;

        // Main Application Loop
        while (!quit)
        {
            // If there are Window messages then process them.
            if (PeekMessage(&m_message, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&m_message);
                DispatchMessage(&m_message);
            }
            // Otherwise, do "Program Loop!~"
            else
            {
                // Framerate Calculation
				FramerateCalculation();

				if (!IsServerConnect())
				{
					MessageBox(NULL, L"與伺服器斷線...", L"連線錯誤", MB_ICONERROR | MB_ICONINFORMATION);
					quit = true;
				}

                // Process Game Time
                GetGameTimer()->Tick();

                // Main Program Loop
                if (!GetAppPause()) 
                {
                    // GamePad Controller handle here.
                    RunPlatformContoller();

                    // Run the Application (Program)
                    RunApp(m_pTimer->DeltaTime());
                }
                else
                {
					// else delay the thread.
                    Sleep(100);
                }
            }

			// Check is Exit App
            if (m_message.message == WM_QUIT)
                break;

        }

        return m_message.wParam;
    }

	void Application::CreateSubWindow(
		std::wstring windowTitle, 
		int32 width, 
		int32 height)
	{
		Window* pWindow = new Window(m_mainWindow);

		pWindow->GenerateWindow(
			m_hInstance,
			m_nCmdShow,
			m_windowClass,
			windowTitle,
			width,
			height);

		// add it into array.
		m_subWindows.push_back(pWindow);
	}

	void Application::CreateSubWindow(
		std::wstring windowTitle, 
		int32 x,
		int32 y, 
		int32 width, 
		int32 height)
	{
		Window* pWindow = new Window(m_mainWindow);

		pWindow->GenerateWindow(
			m_hInstance,
			m_nCmdShow,
			m_windowClass,
			windowTitle,
			x,
			y,
			width,
			height);

		// add it into array.
		m_subWindows.push_back(pWindow);
	}

    // Run Controller depend on what Platform is using
    void Application::RunPlatformContoller()
    {
        if (GetPlatformType() == PlatformType::PC)
            return;


        switch (GetPlatformType())
        {
        case PlatformType::PS:
        {

        } break;

        case PlatformType::PS2:
        {

        } break;

        case PlatformType::PS3:
        {

        } break;

        case PlatformType::PS4:
        {

        } break;

        case PlatformType::XBOXONE:
        case PlatformType::XBOX360:
        {
            dynamic_cast<GamePad*>(m_pPlatformInput)->IsConnected();
        } break;

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
		for (Window* pWindow : m_subWindows)
		{
			pWindow->CalculateFrameStats(GetGameTimer());
		}
	}

	bool Application::IsServerConnect()
	{
		// Socket Client / Server
		if (!GetIsOnlineGame())
			return true;

		return this->getConnection()->Check();
	}

    //====================================================================================--------------------------------------------------------
    // Other Initialize Functions
    //====================================================================================--------------------------------------------------------
    // 連線初始化
    bool Application::InitSocket()
    {
        if (!m_pSocket->Create(m_hostname, m_port))
            return false;

        return true;  // Success create the "Socket" for game client
    }

    // 視窗初始化
    bool Application::InitWindow()
    {
		if (!m_pWindow->GenerateWindow(
			m_hInstance,
			m_nCmdShow,
			m_windowClass,
			m_windowTitle,
			m_screenWidth,
			m_screenHeight))
		{
			return false;
		}

        // Set Main Window
        this->m_mainWindow = m_pWindow->GetHWND();

        return true;    // Success create the "Window" for game client
    }

    // 平台初始化
    bool Application::InitPlatform()
    {

        // Create Platform's Controller (Input Type)
        m_pPlatformInput = PlatformInputFactory::CreatePlatformInput(GetPlatformType());

        // Failed to create the Platform's Controller (Input Type)
        if (!m_pPlatformInput && GetPlatformType() != PlatformType::PC)
            return false;


        return true;
    }

} // end namespace "JCS_GameTool"
