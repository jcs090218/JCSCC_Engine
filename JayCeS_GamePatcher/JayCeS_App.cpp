/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JayCeS_App.h"

#include <GUI_Framework_JCS\JCS_GUI.h>

#include "CommandIdentifier.h"
#include "resource.h"

#include <JcsLib\JcsTools.h>
#include <JayCeS_JCS\JayCeS.h>


JayCeS_App::JayCeS_App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    : JCS_GameResourceS::Application(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
{

}

JayCeS_App::~JayCeS_App()
{

}

bool JayCeS_App::Initialize()
{
    // Set Screen Width and Height before "Application::Initialize", 
    // or else it will not work...
    SetScreenWidth(760);
    SetScreenHeight(800);
    SetWindowTitle(L"JayCeS File Management");

    SetIcon(IDI_JAYCES_GAME_PATCHER);
    SetExeIcon(IDI_MAIN_ICON);

    // Init Application
    if (!Application::Initialize())
    {
        return false;
    }

    return true;
}

// Main Game Loop
void JayCeS_App::RunApp()
{
    // Run the "Program" here.

}

void JayCeS_App::CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    JCS_GUI::JCS_PushButton button;
    button.Create(hWnd, L"Button 1", 50, 220, 100, 24, BUTTON_001);
}

// Design Command Function here...
void JayCeS_App::ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
    case FILE_MENU_NEW:
    {
        

    } break;
    case BUTTON_001:
    {
        JCS_MessageBox(L"Button Titile", L"Button pressed", MB_OK);
    } break;
    }
}

