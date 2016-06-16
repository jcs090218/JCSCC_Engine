#include "TestApp.h"

#include "Game.h"

#include "Resource.h"

TestApp::TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    : JCS_GameTool::Application(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
{
    
}


TestApp::~TestApp()
{
    SafeDeleteObject(m_pGame);
}

bool TestApp::Initialize()
{
    // We wan to see framerate than set it to true
    ShowFrameRate(true);

    SetScreenWidth(1280);
    SetScreenHeight(720);
    SetWindowTitle(L"Direct2D_JCS_Test_VS2013");
    SetIcon(IDI_JCS_FRAMWORK_ICON);
    SetExeIcon(IDI_MAIN_ICON);

    // We are creating an online game
    /*SetIsOnlineGame(true);
    SetHostName("127.0.0.1");
    SetPort(5555);*/

    SetPlatformType(PlatformType::XBOX360);

    // Init Application
    if (!Application::Initialize())
    {
        return false;
    }

    // Create Game
    m_pGame = new Game(GetKeyBoardServer(), GetMouseServer(), this->GetGameTimer());
    // 檢查遊戲初始化...
    if (!m_pGame->Initlialize(this->GetMainWindow()))
    {
        MessageBox(NULL, L"Game does not initailize correctly!", L"Error!!", MB_ICONERROR | MB_ICONINFORMATION);
        return false;
    }

    // Set the GamePad
    m_pGame->SetGamePad(GetPlatformInputAsPtr());
    
    return true;
}

// Main Game Loop
void TestApp::RunApp(float deltaTime)
{
    // Run the game here.
    m_pGame->Run(deltaTime);
}

