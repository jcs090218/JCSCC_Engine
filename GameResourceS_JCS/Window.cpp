#include "Window.h"


#include "Application.h"

#include <GUI_Framework_JCS\Identifier.h>

namespace JCS_GameResourceS
{
    //WindowProc - Handles input sent to the window.
    LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_CREATE:		// 創建時...
        {
            // Create GUI
            Window::s_pApplication->CreateGUI(hWnd, message, wParam, lParam);
        } break;

        case WM_DESTROY:
        {
            PostQuitMessage(0);
        } break;
        
        case WM_COMMAND:
        {
            // Design Command here by any user...
            Window::s_pApplication->ListenCommand(hWnd, message, wParam, lParam);

            // Take care "Common Command" here...
            switch (LOWORD(wParam))
            {
            case IDC_EXIT: { PostQuitMessage(0); } break;
            }
        } break;
        }

        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    // ********************* Global Variables ************************************************
    Window* Window::s_pGlobalWindow = nullptr;
    Application* Window::s_pApplication = nullptr;

    Window::Window(HWND hWnd, WNDPROC wWinProc /*= WinProc*/, Application* app /*= nullptr*/)
        : mhMainWndow(hWnd)
        , mhWinProc(wWinProc)
        , m_screenWidth(0)
        , m_screenHeight(0)
        , m_windowTitle()
    {
        s_pGlobalWindow = this;
        s_pApplication = app;
    }

    Window::~Window()
    {
        s_pGlobalWindow = nullptr;
        s_pApplication = nullptr;
    }

    bool Window::GenerateWindow(HINSTANCE hInstance,
        int32 nCmdShow,
        std::wstring className,
        std::wstring windowTitle,
        int32 width, int32 height)
    {
        this->m_screenWidth = width;
        this->m_screenHeight = height;
        m_windowTitle = windowTitle;

        return GenerateWindow(hInstance,
            nCmdShow, className, windowTitle,
            (GetSystemMetrics(SM_CXSCREEN) - width) / 2,		// set to the middle of the screen
            (GetSystemMetrics(SM_CYSCREEN) - height) / 2,		// set to the middle of the screen
            width, height);
    }

    //Generic GenerateWindow function.
    bool Window::GenerateWindow(HINSTANCE hInstance,
        int nCmdShow,
        std::wstring className, std::wstring windowTitle,
        int x, int y, int width, int height)
    {
        WNDCLASSEX wcex;

        ZeroMemory(&wcex, sizeof(WNDCLASSEX));
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.cbSize = sizeof(wcex);
        wcex.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = mhWinProc;
        wcex.hInstance = hInstance;
        wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
        wcex.lpszClassName = className.c_str();
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(s_pApplication->GetIcon()), IMAGE_ICON, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CXICON), 0);
        wcex.hIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(s_pApplication->GetIcon()), IMAGE_ICON, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CXICON), 0);

        if (!RegisterClassEx(&wcex))
        {
            OutputDebugString(L"\nFAILED TO CREATE WINDOW CLASS\n");
            return false;
        }

        RECT wr = { 0, 0, width, height };
        AdjustWindowRect(&wr, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, FALSE);
        UINT widthX = wr.right - wr.left;			// use to measure and adjust window display.. (width)
        UINT heightX = wr.bottom - wr.top;			// use to mesure and adjust window display.. (height)

        mhMainWndow = CreateWindowEx(NULL, className.c_str(), windowTitle.c_str(),
            WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
            x, y,
            widthX,
            heightX,
            NULL,
            NULL,
            hInstance,
            NULL);

        if (!mhMainWndow)
        {
            MessageBox(NULL, L"CreateWindow Failed.", NULL, NULL);
            return false;
        }

        ShowWindow(mhMainWndow, nCmdShow);
        UpdateWindow(mhMainWndow);

        return true;
    }

}

