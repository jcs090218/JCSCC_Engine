#include "Application.h"

#include "Window.h"

namespace JCS_GameResourceS
{
    Application::Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow)
        : m_hInstance(hInstance)
        , m_hPrevInstance(hPrevInstance)
        , m_lpCmdLine(lpCmdLine)
        , m_nCmdShow(nCmdShow)
        // Windows
        , m_pWindow(nullptr)
        , m_mainWindow()
        , m_message()
        , m_windowTitle(L"D3DVS2013_Framework_JCS")
        , m_windowClass(L"Framework Development Class")
        , m_screenWidth(1280)		// default SCREEN WIDTH
        , m_screenHeight(720)		// default SCREEN HEIGHT
        , m_icon(101)               // default Icon defines
        , m_exeIcon(102)          // default Small Icon defines
    {
        // Create Objects
        m_pWindow = new Window(m_mainWindow, WinProc, this);
    }

    Application::~Application()
    {
        SafeDeleteObject(m_pWindow);
    }

    bool Application::Initialize()
    {

        // 檢查視窗初始化...
        if (!InitWindow())
        {
            //MessageBox(NULL, L"Window does not create correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
            return false;
        }

        return true;
    }

    uint32 Application::Run()
    {

        // Main Application Loop
        while (true)
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
                // Main Program Loop
                if (!GetAppPause())
                {
                    // Run the Application (Program)
                    RunApp();
                }
                else
                {
                    Sleep(100);
                }
            }

            if (m_message.message == WM_QUIT)
                break;

        }

        return m_message.wParam;
    }

    //--------------------------------------------------------------------------------------------------------------------------------------------
    // Other Initialize Functions
    //--------------------------------------------------------------------------------------------------------------------------------------------
    // 視窗初始化
    bool Application::InitWindow()
    {
        if (!m_pWindow->GenerateWindow(m_hInstance, m_nCmdShow, m_windowClass, m_windowTitle, m_screenWidth, m_screenHeight))
            return false;

        // Set Main Window
        this->m_mainWindow = m_pWindow->GetHWND();

        return true;	// Success create the "Window" for game client
    }

}

