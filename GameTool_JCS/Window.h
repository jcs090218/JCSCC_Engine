#ifndef __WINDOW_H__
/**
 * $File: Window.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __WINDOW_H__

#include <GameInput_JCS\DirectInput\Keyboard.h>
#include <GameInput_JCS\DirectInput\Mouse.h>

#include <GameInterface_JCS\JCS_Window.h>


namespace JCS_GameTool
{
	LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    //====================================================================================
    // Class Name : Window 
    //
    // Description : Object handle the window in Windows OS.
    //====================================================================================
    class Window 
        : public JCS_GameInterface::JCS_Window
    {
    private:
        HWND mhMainWndow;        // handle for window
        WNDPROC mhWinProc;

		int32 m_screenWidth, m_screenHeight;
		uint32 m_icon, m_exeIcon;   // application icon settings.

		// window id.
		uint32 m_windowID = 0;

        std::wstring m_windowTitle;

		KeyboardServer* m_pKeyBoardServer;        // keyboard input device
		MouseServer* m_pMouseServer;

    public:
		// Constructor / Destructor.
        Window(HWND hWnd, WNDPROC wWinProc = WinProc);
        virtual ~Window();

		HWND GenerateWindow(HINSTANCE hInstance,
            int32 nCmdShow,
            std::wstring className,
            std::wstring windowTitle,
            int32 width, int32 height);
		HWND GenerateWindow(HINSTANCE hInstance,
            int32 nCmdShow,
            std::wstring className,
            std::wstring windowTitle,
            int32 x, int32 y, int32 width, int32 height);

		/* Calculate frame state? */
        virtual void CalculateFrameStats(GameTimer* pTimer) override;

		/* Check the window name type. */
		bool IsName(std::wstring cmpName) { return (this->m_windowTitle == cmpName); }

        /** setter **/
		/** Set the inside icon? */
		void SetIcon(const uint32 icon) { this->m_icon = icon; }
		/** Set the outside icon? */
		void SetExeIcon(const uint32 icon) { this->m_exeIcon = icon; }

        /** getter **/
        HWND GetHWND() const { return this->mhMainWndow; }
        WNDPROC getWinProc() const { return this->mhWinProc; }
        int32 GetScreenWidth() const { return this->m_screenWidth; }
        int32 GetScreenHeight() const { return this->m_screenHeight; }
        std::wstring GetWindowTitle() const { return this->m_windowTitle; }

		/** Return Icon in this application. */
		uint32 GetIcon() const { return this->m_icon; }
		/** Return External-Icon in this application */
		uint32 GetExeIcon() const { return this->m_exeIcon; }

		KeyboardServer* GetKeyboardServer() const { return this->m_pKeyBoardServer; }
		MouseServer* GetMouseServer() const { return this->m_pMouseServer; }
    };

}

#endif // __WINDOW_H__
