/**
 * $File: Game.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Game.h"

JCS_GameTool::GameManager* Game::gm = nullptr;
JCS_GameTool::SoundManager* Game::sm = nullptr;
JCS_GameTool::InputManager* Game::im = nullptr;
JCS_GameTool::DeviceManager* Game::dm = nullptr;
JCS_GameTool::SceneManager* Game::sem = nullptr;

Game::Game(JCS_GameInput::KeyboardServer* kServer, JCS_GameInput::MouseServer* mServer, GameTimer* mTimer)        // init GAME
    : m_pGameTimer(mTimer)
    , speedX(0)
    , speedY(0)
    , testSprite2D(nullptr)
    , rect(nullptr)
    , circle(nullptr)
    , capsule(nullptr)
    , m_pHexagon(nullptr)
{
    im = JCS_GameTool::InputManager::GetInstance();
    im->setKeyboard(kServer);
    im->setMouse(mServer);
}


Game::~Game()
{
    // Managers
	JCS_GameTool::GameManager::DestroyInstance();
	JCS_GameTool::SceneManager::DestroyInstance();        // 這個目前必須在 Managers 上面
	JCS_GameTool::SoundManager::DestroyInstance();
	JCS_GameTool::InputManager::DestroyInstance();
	JCS_GameTool::DeviceManager::DestroyInstance();
}

bool Game::Initlialize(HWND hWnd)
{
    // Managers
    sm = JCS_GameTool::SoundManager::GetInstance(hWnd);
    gm = JCS_GameTool::GameManager::GetInstance();
    dm = JCS_GameTool::DeviceManager::GetInstance();
    dm->CreateDevice(API_Type::DIRECT2D, hWnd);
    sem = JCS_GameTool::SceneManager::GetInstance(API_Type::DIRECT2D, SceneType::SCENE_2D);

    ///////// Objects
    sm->playBGM(static_cast<TCHAR*>(L"data/test.wav"));

    testSprite2D = new JCS_D2DEngine::Sprite2D(L"Sprite/PlayerPaper.png", dm->GetDirect2DDeviceAsRef());

    rect = new JCS_D2DEngine::Rectangle2D(500.0f, 250.0f, 300.0f, 250.0f, dm->GetDirect2DDeviceAsRef());
    rect2 = new JCS_D2DEngine::Rectangle2D(150, 200, 200.0f, 150.0f, dm->GetDirect2DDeviceAsRef());
    circle = new JCS_D2DEngine::Circle2D(30.0f, dm->GetDirect2DDeviceAsRef(), true);
    circle->setPosition(500, 300);
    circle2 = new JCS_D2DEngine::Circle2D(20.0f, dm->GetDirect2DDeviceAsRef(), true);
    circle2->setPosition(500, 400);
    capsule = new JCS_D2DEngine::Capsule2D(20.0f, 50.0f, dm->GetDirect2DDeviceAsRef());
    capsule->setPosition(300, 400);
    capsule2 = new JCS_D2DEngine::Capsule2D(30.0f, 70.0f, dm->GetDirect2DDeviceAsRef());
    capsule2->setPosition(400, 200);
    m_pHexagon = new JCS_D2DEngine::Hexagon2D(50.0f, dm->GetDirect2DDeviceAsRef(), true);
    m_pHexagon->setPosition(500, 400);

    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(rect);
    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(rect2);
    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(circle);
    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(circle2);
    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(capsule);
    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(capsule2);
    sem->GetDirect2D_Scene2DAsPtr()->AddGameObject2DToScene(m_pHexagon);
    sem->GetDirect2D_Scene2DAsPtr()->AddSprite2DToScene(testSprite2D);

    // Initialize all added scene object
    sem->GetDirect2D_Scene2DAsPtr()->initialize();
    //sem->getScene2D()->thread_initialize(*m_pGameTimer);

    return true;
}

void Game::Run(float deltaTime)
{
    if (!gm->IsGamePause())
    {
        Update(deltaTime);
        Draw(deltaTime);
    }
    else 
    {
        Sleep(100);        // pause
    }
}

void Game::Update(float deltaTime)
{    
    if (im->getKeyboard()->KeyIsPressed(VK_DELETE)) sm->playCompleteShot((TCHAR*)L"data/sound01.wav");

    if (im->getKeyboard()->KeyIsPressed(VK_UP)) { 
        rect->velocity->y = -mainSpeed;            // 這樣才叫有 impl "gametime"
    } else if (im->getKeyboard()->KeyIsPressed(VK_DOWN)) {
        rect->velocity->y = mainSpeed; 
    } else { 
        rect->velocity->y = 0; 
    }

    if (im->getKeyboard()->KeyIsPressed(VK_LEFT)) { 
        rect->velocity->x = -mainSpeed; 
    } else if (im->getKeyboard()->KeyIsPressed(VK_RIGHT)) { 
        rect->velocity->x = mainSpeed; 
    } else {
        rect->velocity->x = 0; 
    }

    if (im->getMouse()->IsInWindow() && im->getMouse()->LeftIsPressed()) {
        dynamic_cast<JCS_D2DEngine::Hexagon2D*>(m_pHexagon)->rotation_rotate(90);
    }
    if (im->getMouse()->IsInWindow() && im->getMouse()->RightIsPressed()) {
        dynamic_cast<JCS_D2DEngine::Hexagon2D*>(m_pHexagon)->revolution_rotate(*capsule, -90);
    }

    if (im->getKeyboard()->KeyIsPressed(VK_ADD)) {
        circle->velocity->y = -300;
    }
    
    capsule->velocity->x = 10;
    circle->velocity->x = 300;

    if (im->getGamePad_XBox360_AsPtr()->isButtonPressed(XINPUT_GAMEPAD_A)) {
        dynamic_cast<JCS_D2DEngine::Hexagon2D*>(m_pHexagon)->rotation_rotate(90);
    }
    if (im->getGamePad_XBox360_AsPtr()->isButtonPressed(XINPUT_GAMEPAD_B)) {
        dynamic_cast<JCS_D2DEngine::Hexagon2D*>(m_pHexagon)->revolution_rotate(*capsule, -90);
    }


    //if (circle2->CircletoCircle(*circle)) {
    //    //DP(L"\nOP");
    //    circle->velocity->x += circle2->velocity->x;
    //    circle->velocity->y += circle2->velocity->y;
    //}
    //else {
    //    //DP(L"\nCool");

    //    int friction = 5;

    //    if (circle->velocity->x > 0) {
    //        circle->velocity->x -= friction;
    //    }
    //    else if (circle->velocity->x < 0) {
    //        circle->velocity->x += friction;
    //    }

    //    if (circle->velocity->y > 0) {
    //        circle->velocity->y -= friction;
    //    }
    //    else if (circle->velocity->y < 0) {
    //        circle->velocity->y += friction;
    //    }
    //}

    if (sem != nullptr) sem->update(deltaTime);
}

/**
 *  不會動的物體 Draw他就行了...
 */
void Game::Draw(float deltaTime)
{
    /********************************Direct2D******************************************/
    dm->GetDirect2DDeviceAsRef().BeginRender();            // Direct2D 開始
    dm->GetDirect2DDeviceAsRef().SetTransform(D2D1::Matrix3x2F::Identity());
    dm->GetDirect2DDeviceAsRef().ClearScreen(0.0f, 0.0f, 0.0f, 1.0f);
    //////////////////////////////////////////////////////////////////////

    dm->GetDirect2DDeviceAsRef().drawCircle(100, 100, 50, 1.0f, 0.0f, 0.0f, 1.0f);
    dm->GetDirect2DDeviceAsRef().drawCircle(400, 200, 75, 1.0f, 1.0f, 0.0f, 1.0f);
    dm->GetDirect2DDeviceAsRef().drawElipse(700, 450, 30.0f, 40.0f);
    dm->GetDirect2DDeviceAsRef().drawRectangle(0, 0, 10.0f, 20.0f);
    dm->GetDirect2DDeviceAsRef().drawSquare(20.0f, 20.0f, 50.0f);

    if (sem != nullptr) 
        sem->draw();

    //////////////////////////////////////////////////////////////////////
    dm->GetDirect2DDeviceAsRef().EndRender();            // Direct2D 結束
}

