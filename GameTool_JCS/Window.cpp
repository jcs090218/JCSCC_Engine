/**
 * $File: Window.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Window.h"

#include "GameTool_StdAfx.h"


// Input Devices
#include "GameTimer.h"


#define WM_SOCKET 104

// Using algorithm's version, because is "inline 
// template function"
#undef min
#undef max


namespace JCS_GameTool
{

    //WindowProc - Handles input sent to the window.
    LRESULT CALLBACK WinProc(
		HWND hWnd, 
		UINT message, 
		WPARAM wParam, 
		LPARAM lParam)
    {
		Window* pThis;

		if (message == WM_NCCREATE)
		{
			pThis = static_cast<Window*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

			SetLastError(0);
			if (!SetWindowLongPtr(hWnd, GWL_USERDATA, reinterpret_cast<LONG_PTR>(pThis)))
			{
				if (GetLastError() != 0)
					return FALSE;
			}
		}
		else
		{
			pThis = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWL_USERDATA));
		}

		if (pThis != nullptr)
		{

			JCS_GameInput::MouseServer* pMouseServer = pThis->GetMouseServer();
			JCS_GameInput::KeyboardServer* pKeybaordServer = pThis->GetKeyboardServer();

			switch (message)
			{
			case WM_CREATE:        // 創建時...
			{
				//if (!client->initialize(hWnd)) {        // 如果創建連線失敗...
				//    SendMessage(hWnd, WM_DESTROY, NULL, NULL);
				//}
			} break;

			case WM_DESTROY:
			{
				PostQuitMessage(0);
			} break;

			case WM_SOCKET:    // 連結後...
			{
				if (WSAGETSELECTERROR(lParam))
				{
					MessageBox(hWnd, L"Connection to server failed", L"Error", MB_OK | MB_ICONERROR);
					SendMessage(hWnd, WM_DESTROY, NULL, NULL);
					break;
				}
			} break;

			// ************ KEYBOARD MESSAGES ************ //
			case  WM_KEYDOWN:
			{
				pKeybaordServer->OnKeyPressed(wParam);
			} break;

			case  WM_KEYUP:
			{
				pKeybaordServer->OnKeyReleased(wParam);
			} break;

			case WM_CHAR:
			{
				pKeybaordServer->OnChar(wParam);
			} break;

			// ************ END KEYBOARD MESSAGES ************ //

			// ************ MOUSE MESSAGES ************ //
			case WM_MOUSEMOVE:
			{
				int32 x = static_cast<short>(LOWORD(lParam));
				int32 y = static_cast<short>(HIWORD(lParam));
				int32 screenWidth = pThis->GetScreenWidth();
				int32 screenHeight = pThis->GetScreenHeight();

				if (x > 0 && x < screenWidth && y > 0 &&
					y < screenHeight)
				{

					// On mouse move.
					pMouseServer->OnMouseMove(x, y);
					if (!pMouseServer->IsInWindow())
					{
						SetCapture(hWnd);
						pMouseServer->OnMouseEnter();
					}
				}
				else
				{
					if (wParam & (MK_LBUTTON | MK_RBUTTON))
					{
						x = std::max(0, x);
						x = std::min(screenWidth - 1, x);
						y = std::max(0, y);
						y = std::min(screenHeight - 1, y);
						pMouseServer->OnMouseMove(x, y);
					}
					else
					{
						ReleaseCapture();
						pMouseServer->OnMouseLeave();
						pMouseServer->OnLeftReleased();
						pMouseServer->OnRightReleased();
					}
				}
			} break;

			case WM_LBUTTONDOWN:
			{
				pMouseServer->OnLeftPressed();
			} break;

			case WM_RBUTTONDOWN:
			{
				pMouseServer->OnRightPressed();
			} break;

			case WM_LBUTTONUP:
			{
				pMouseServer->OnLeftReleased();
			} break;

			case WM_RBUTTONUP:
			{
				pMouseServer->OnRightReleased();
			} break;

			// ************ END MOUSE MESSAGES ************ //
			} // end switch(message) {  }
		}

        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    // ********************* Global Variables ************************************************
    GameError* g_pThrownError = nullptr;

    Window::Window(HWND hWnd, WNDPROC wWinProc /*= WinProc*/)
        : mhMainWndow(hWnd)
        , mhWinProc(wWinProc)
        , m_screenWidth(0)
        , m_screenHeight(0)
        , m_windowTitle()
		, m_windowID(0)
		, m_icon(101)               // default Icon defines
		, m_exeIcon(102)          // default Small Icon defines
    {
		m_pKeyBoardServer = new JCS_GameInput::KeyboardServer();
		m_pMouseServer = new JCS_GameInput::MouseServer();
    }


    Window::~Window()
    {
        SafeDeleteObject(g_pThrownError);

		SafeDeleteObject(m_pKeyBoardServer);
		SafeDeleteObject(m_pMouseServer);
    }

	HWND Window::GenerateWindow(
		HINSTANCE hInstance,
        int32 nCmdShow,
        std::wstring className,
        std::wstring windowTitle,
        int32 width, 
		int32 height)
    {
        return GenerateWindow(hInstance,
            nCmdShow, className, windowTitle,
            (GetSystemMetrics(SM_CXSCREEN) - width) / 2,        // set to the middle of the screen
            (GetSystemMetrics(SM_CYSCREEN) - height) / 2,        // set to the middle of the screen
            width, height);
    }

    //Generic GenerateWindow function.
	HWND Window::GenerateWindow(
		HINSTANCE hInstance,
        int32 nCmdShow,
        std::wstring className, 
		std::wstring windowTitle,
        int32 x, 
		int32 y, 
		int32 width, 
		int32 height)
    {
        WNDCLASSEX wcex;

        ZeroMemory(&wcex, sizeof(WNDCLASSEX));
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.cbSize = sizeof(wcex);
        wcex.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = mhWinProc;
        wcex.hInstance = hInstance;
        wcex.hbrBackground = CreateSolidBrush(GetSysColor(COLOR_BACKGROUND));
        wcex.lpszClassName = className.c_str();
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(GetIcon()), IMAGE_ICON, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CXICON), 0);
        wcex.hIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(GetIcon()), IMAGE_ICON, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CXICON), 0);

        if (!RegisterClassEx(&wcex)) 
        {
            OutputDebugString(L"\nFAILED TO CREATE WINDOW CLASS\n");
            return false;
        }

        RECT wr = { 0, 0, width, height };
        AdjustWindowRect(&wr, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, FALSE);
        UINT widthX = wr.right - wr.left;            // use to measure and adjust window display.. (width)
        UINT heightX = wr.bottom - wr.top;            // use to mesure and adjust window display.. (height)

		HWND winHandle = CreateWindowEx(
			NULL, 
			className.c_str(),
			windowTitle.c_str(),
            WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
            x, y,
            widthX,
            heightX,
            NULL,
            NULL,
            hInstance,
            NULL);

        if (!winHandle)
        {
            MessageBox(NULL, L"Create Window Failed.", NULL, NULL);
            return false;
        }

		// first assign.
		if (!mhMainWndow)
			this->mhMainWndow = winHandle;

		// save the address of the class as the Window's USERDATA.
		SetWindowLong(mhMainWndow, GWLP_USERDATA, (long)this);

		this->m_screenWidth = width;
		this->m_screenHeight = height;
		this->m_windowTitle = windowTitle;

        ShowWindow(mhMainWndow, nCmdShow);
        UpdateWindow(mhMainWndow);

        return winHandle;
    }


    void Window::CalculateFrameStats(GameTimer* pTimer)
    {
        // Code computes the average frames per second, and also the 
        // average time it takes to render one frame.  These stats 
        // are appended to the window caption bar.

        static int32 frameCnt = 0;
        static float32 timeElapsed = 0.0f;

        ++frameCnt;

        // Compute averages over one second period.
        if ((pTimer->TotalTime() - timeElapsed) >= 1.0f)
        {
            float32 fps = static_cast<float32>(frameCnt); // fps = frameCnt / 1
            float32 mspf = 1000.0f / fps;

            std::wostringstream outs;
            outs.precision(6);
            outs << m_windowTitle << L"    "
                << L"FPS: " << fps << L"    "
                << L"Frame Time: " << mspf << L" (ms)";
            SetWindowText(mhMainWndow, outs.str().c_str());

            // Reset for next average.
            frameCnt = 0;
            timeElapsed += 1.0f;
        }
    }

}

