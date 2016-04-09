/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "TestApp.h"


#include "resource.h"
#include "TestGame.h"
#include "StdAfx.h"

TestApp::TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    : JCS_GameTool::Application(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
{

}

TestApp::~TestApp()
{
    if (m_pGame)
    {
        delete m_pGame;
        m_pGame = nullptr;
    }
}

bool TestApp::Initialize()
{
    // We wan to see framerate than set it to true
    ShowFrameRate(true);

    SetScreenWidth(1280);
    SetScreenHeight(720);
    SetWindowTitle(WIDOW_TITLE);
    SetIcon(TEST_GAME_ICON);
    SetExeIcon(IDI_MAIN_ICON);

    // We are creating an online game
    SetIsOnlineGame(true);
    SetHostName("127.0.0.1");
    SetPort(5555);

    // Init Application
    if (!Application::Initialize())
    {
        return false;
    }

    m_pGame = new TestGame(GetKeyBoardServer(), GetMouseServer());
    if (!m_pGame->Initialize(this->GetMainWindow()))
    {
        MessageBox(NULL, L"Game does not initailize correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
        return false;
    }

    return true;
}

void TestApp::RunApp(float deltaTime)
{
    m_pGame->Run(deltaTime);
}


