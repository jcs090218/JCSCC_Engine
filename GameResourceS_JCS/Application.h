/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __APPLICATION_H__
#define __APPLICATION_H__


#include "GameResourceS_StdAfx.h"

namespace JCS_GameResourceS
{
    class Window;

    //------------------------------------------------------------------------------------
    // Name : Application 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class Application
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

        // Program Control
        bool m_appPaused;        // use when we want to stop the program

    public:
        Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow);
        virtual ~Application();

        virtual bool Initialize();
        uint32 Run();

        virtual void CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;    // Design GUI in this function
        virtual void ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;

        // -- setter
        void SetScreenWidth(const int32 screenWidth) { this->m_screenWidth = screenWidth; }
        void SetScreenHeight(const int32 screenHeight){ this->m_screenHeight = screenHeight; }
        void SetWindowTitle(const std::wstring windowTitle){ this->m_windowTitle = windowTitle; }
        void SetAppPause(const bool pause) { this->m_appPaused = pause; }
        void SetIcon(const uint32 icon) { this->m_icon = icon; }
        void SetExeIcon(const uint32 icon) { this->m_exeIcon = icon; }

        // -- getter
        // Window
        Window* GetWindow() const { return this->m_pWindow; }
        HWND GetMainWindow() { return this->m_mainWindow; }
        uint32 GetIcon() const { return this->m_icon; }
        uint32 GetExeIcon() const { return this->m_exeIcon; }

        // Program Control
        bool GetAppPause() const { return this->m_appPaused; }

    protected:
        bool InitWindow();        // Create GameWindow

        // Override this enable to run the game
        virtual void RunApp() = 0;
    };

}

typedef JCS_GameResourceS::Application Application;

#endif // __APPLICATION_H__

