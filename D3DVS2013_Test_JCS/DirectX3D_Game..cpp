/**
 * $File: DirectX3D_Game.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "DirectX3D_Game.h"


#include "StdAfx.h"

DirectX3D_Game::DirectX3D_Game(JCS_GameInput::KeyboardServer* kServer, JCS_GameInput::MouseServer* mServer)
{
    im = JCS_GameTool::InputManager::GetInstance();
    im->setKeyboard(kServer);
    im->setMouse(mServer);
}

DirectX3D_Game::~DirectX3D_Game()
{
    SafeDeleteObject(player);
    SafeDeleteObject(testSprite);
    SafeDeleteObject(testAnimation);

    //SafeReleaseCOM(meshTeapot);

	JCS_GameTool::GameManager::DestroyInstance();
	JCS_GameTool::SceneManager::DestroyInstance();        // 這個目前必須在 Managers 上面
	JCS_GameTool::SoundManager::DestroyInstance();
	JCS_GameTool::InputManager::DestroyInstance();
	JCS_GameTool::DeviceManager::DestroyInstance();
}

bool DirectX3D_Game::Initlialize(HWND hWnd)
{
    sm = JCS_GameTool::SoundManager::GetInstance(hWnd);
    gm = JCS_GameTool::GameManager::GetInstance();
    dm = JCS_GameTool::DeviceManager::GetInstance();
    dm->CreateDevice(API_Type::DIRECTX3D_9, hWnd);
    sem = JCS_GameTool::SceneManager::GetInstance(API_Type::DIRECTX3D_9, SceneType::SCENE_3D);

    sm->playBGM(static_cast<TCHAR*>(L"data/test.wav"));


    player = new JCS_D3DX_v9_Engine::GameObject3D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    if (!player->Initialize(dm->GetDriectX3D_v9_DeviceAsPtr()->GetDevice(), L"Sprite/PlayerPaper.png", 58, 86, 255))
        return false;
    player->getSprite()->setPivot(D3DXVECTOR2(58 / 2, 86 / 2));        // 設置中心點

    testSprite = new JCS_D3DX_v9_Engine::DisplayObject(200, 300);
    if (!testSprite->Initialize(dm->GetDriectX3D_v9_DeviceAsPtr()->GetDevice(), L"Sprite/PlayerPaper.png"))
        return false;

    testAnimation = new JCS_D3DX_v9_Engine::DisplayObject(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 21, 0, 0, false);
    if (!testAnimation->Initialize(dm->GetDriectX3D_v9_DeviceAsPtr()->GetDevice(), L"Sprite/Panel3.png", 1))
        return false;

    // 3d model
    //D3DXCreateTeapot(gDevice->d3ddev, &meshTeapot, NULL);

    return true;
}

void DirectX3D_Game::Run(float deltaTime)
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

void DirectX3D_Game::Update(float deltaTime)
{
    if (GetAsyncKeyState(67))
    {
        std::wstring message = L"C key is pressed";
        MessageBox(NULL, message.c_str(), NULL, NULL);
    }

    //DP1(L"\nGameTime: %f", deltaTime);
    //DP1(L"Position.x: %d\n", sizeof(JCS_GameTool::KeyboardClient));

    if (im->getMouse()->IsInWindow() && im->getMouse()->LeftIsPressed()) player->ScaleBounce(2, 40.0f, 10);

    // Test
    if (im->getKeyboard()->KeyIsPressed(VK_CONTROL)) player->Shake(2, 1.0f);
    if (im->getKeyboard()->KeyIsPressed(0x41)) player->ScaleChange(2, 116.0f, 172.0f);
    if (im->getKeyboard()->KeyIsPressed(VK_ADD)) player->AlphaChange(2, 1);
    if (im->getKeyboard()->KeyIsPressed(VK_BACK)) player->MoveTo(1, D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));
    if (im->getKeyboard()->KeyIsPressed(VK_DELETE)) sm->playCompleteShot((TCHAR*)L"data/sound01.wav");
    if (im->getKeyboard()->KeyIsPressed(VK_F1)) testAnimation->getAnimatObj()->PlayAnimationWithSpriteSheet(deltaTime, D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), 21, true);

    if (im->getKeyboard()->KeyIsPressed(VK_UP)) player->y -= mainSpeed * deltaTime;        // 這樣才叫有 impl "gametime"
    if (im->getKeyboard()->KeyIsPressed(VK_DOWN))player->y += mainSpeed * deltaTime;
    if (im->getKeyboard()->KeyIsPressed(VK_LEFT))player->x -= mainSpeed * deltaTime;
    if (im->getKeyboard()->KeyIsPressed(VK_RIGHT))player->x += mainSpeed * deltaTime;

    // Update our sprite and other game logic
    if (player != NULL) player->Update(deltaTime);
}

void DirectX3D_Game::Draw(float deltaTime)
{
    // Simple RGB value for the background so use XRGB instead of ARGB
    dm->GetDriectX3D_v9_DeviceAsPtr()->Clear(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
    dm->GetDriectX3D_v9_DeviceAsPtr()->ClearDepth();
    dm->GetDriectX3D_v9_DeviceAsPtr()->BeginRender();
    ////////////////////////////////////////////////////////////////////

    DirectX3D_Game::update(deltaTime);
    if (player) player->Draw(deltaTime);
    if (testSprite) testSprite->Draw(deltaTime);
    if (testAnimation) testAnimation->Draw(deltaTime);

    //meshTeapot->DrawSubset(0);

    ////////////////////////////////////////////////////////////////////
    dm->GetDriectX3D_v9_DeviceAsPtr()->EndRender();
    dm->GetDriectX3D_v9_DeviceAsPtr()->RenderPresent();
}

void DirectX3D_Game::update(float deltaTime)
{
    speedX += deltaTime;
    //D3DXMATRIX matView;    // the view transform matrix
    //D3DXMatrixLookAtLH(&matView,
    //    &D3DXVECTOR3(speedX, 2.0f, 6.0f),    // the camera position
    //    &D3DXVECTOR3(0.0f, 0.0f, 0.0f),    // the look-at position
    //    &D3DXVECTOR3(0.0f, 1.0f, 0.0f));    // the up direction
    //gDevice->d3ddev->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView

    //D3DXMATRIX matProjection;     // the projection transform matrix
    //D3DXMatrixPerspectiveFovLH(&matProjection,
    //    D3DXToRadian(45),    // the horizontal field of view
    //    (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT, // aspect ratio
    //    1.0f,    // the near view-plane
    //    100.0f);    // the far view-plane
    //gDevice->d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);    // set the projection

    //D3DXVECTOR3 vCamera(speedX, speedX, speedX);
    //D3DXVECTOR3 vLookAt(speedX, speedX, speedX);
    //D3DXVECTOR3 vUpVector(0.0f, 1.0f, 0.0f);
    //D3DXMATRIX matView;
    //D3DXMatrixLookAtLH(&matView, &vCamera, &vLookAt, &vUpVector);
    ////gm->getGrapchicsDevice()->d3ddev->SetTransform(D3DTS_VIEW, &matView);

    //D3DXMATRIX matProj;
    //D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI/4, 1.0f, 1.0f, 100.0f);
    ////gm->getGrapchicsDevice()->d3ddev->SetTransform(D3DTS_PROJECTION, &matProj);

}

