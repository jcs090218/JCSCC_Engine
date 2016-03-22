#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Application.h"

#include <GameInterface_JCS\JCS_Window.h>

namespace JCS_GameTool
{
	// Main Windoiw Callback
	LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    //------------------------------------------------------------------------------------
    // Name : Window 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
	class Window 
        : public JCS_GameInterface::JCS_Window
	{
    public:
        static Application* s_pApplication;
        static Window* s_pGlobalWindow;		// singleton pattern

	private:
		HWND mhMainWndow;		// handle for window
		WNDPROC mhWinProc;

		int32 m_screenWidth, m_screenHeight;
		std::wstring m_windowTitle;

	public:
		Window(HWND hWnd, WNDPROC wWinProc = WinProc, Application* app = nullptr);
		virtual ~Window();

		bool GenerateWindow(HINSTANCE hInstance,
			int32 nCmdShow,
			std::wstring className,
			std::wstring windowTitle,
			int32 width, int32 height);
		bool GenerateWindow(HINSTANCE hInstance,
			int32 nCmdShow,
			std::wstring className,
			std::wstring windowTitle,
			int32 x, int32 y, int32 width, int32 height);

		virtual void CalculateFrameStats(GameTimer* pTimer) override;

		// setter

		// getter
        static Window* GetMainWindow() { return s_pGlobalWindow; }
		HWND GetHWND() const { return this->mhMainWndow; }
		WNDPROC getWinProc() const { return this->mhWinProc; }
		int32 GetScreenWidth() const { return this->m_screenWidth; }
		int32 GetScreenHeight() const { return this->m_screenHeight; }
		std::wstring GetWindowTitle() const { return this->m_windowTitle; }

	};

	inline Window* getWindow()
	{
		return Window::GetMainWindow();
	}

}


#endif // __WINDOW_H__

