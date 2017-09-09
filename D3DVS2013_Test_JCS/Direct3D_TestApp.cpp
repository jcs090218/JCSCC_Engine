/**
 * $File: Direct3D_TestApp.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "DirectX3D_TestApp.h"

#include "Resource.h"

DirectX3D_TestApp::DirectX3D_TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    : JCS_GameTool::Application(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
    , m_pGame(nullptr)
    , m_pGame11(nullptr)
{

}

DirectX3D_TestApp::~DirectX3D_TestApp()
{
    SafeDeleteObject(m_pGame);
    SafeDeleteObject(m_pGame11);
}

bool DirectX3D_TestApp::Initialize()
{
    // We wan to see framerate than set it to true
    ShowFrameRate(true);

    SetScreenWidth(1280);
    SetScreenHeight(720);
    SetWindowTitle(L"Direct3D_JCS_Test_VS2013");
    SetIcon(IDI_JCS_FRAMWORK_ICON);
    SetExeIcon(IDI_MAIN_ICON);

    //// We are creating an online game
    //SetIsOnlineGame(true);
    //SetHostName("127.0.0.1");
    //SetPort(5555);

    // Init Application
    if (!Application::Initialize())
    {
        return false;
    }

#ifdef DIRECTX_9
    // Create Game
    m_pGame = new DirectX3D_Game(GetKeyBoardServer(), GetMouseServer());
    // 檢查遊戲初始化...
    if (!m_pGame->Initlialize(this->GetMainWindow()))
    {
        MessageBox(NULL, L"Game does not initailize correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
        return false;
    }
#endif 

#ifdef DIRECTX_11
    m_pGame11 = new DirectX11_Game(GetKeyBoardServer(), GetMouseServer());
    // 檢查遊戲初始化...
    if (!m_pGame11->Initlialize(this->GetMainWindow()))
    {
        MessageBox(NULL, L"Game does not initailize correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
        return false;
    }
#endif 

    return true;
}

void DirectX3D_TestApp::RunApp(float deltaTime)
{
#ifdef DIRECTX_9
    m_pGame->Run(deltaTime);
#endif 
#ifdef DIRECTX_11
    m_pGame11->Run(deltaTime);
#endif
}


