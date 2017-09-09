/**
 * $File: DirectX11_Game.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "DirectX11_Game.h"

#include <DirectXColors.h>

DirectX11_Game::DirectX11_Game(JCS_GameInput::KeyboardServer* kServer, JCS_GameInput::MouseServer* mServer)
    : m_pInterface(nullptr)
{
    im = JCS_GameTool::InputManager::GetInstance();
    im->setKeyboard(kServer);
    im->setMouse(mServer);
}

DirectX11_Game::~DirectX11_Game()
{
    SafeDeleteObject(m_pInterface);
    SafeDeleteObject(m_pAnimation);

	JCS_GameTool::GameManager::DestroyInstance();
	JCS_GameTool::SceneManager::DestroyInstance();        // 這個目前必須在 Managers 上面
	JCS_GameTool::SoundManager::DestroyInstance();
	JCS_GameTool::InputManager::DestroyInstance();
	JCS_GameTool::DeviceManager::DestroyInstance();
}

bool DirectX11_Game::Initlialize(HWND hWnd)
{
    sm = JCS_GameTool::SoundManager::GetInstance(hWnd);
    gm = JCS_GameTool::GameManager::GetInstance();
    dm = JCS_GameTool::DeviceManager::GetInstance();
    dm->CreateDevice(API_Type::DIRECTX3D_11, hWnd);
    sem = JCS_GameTool::SceneManager::GetInstance(API_Type::DIRECTX3D_11, SceneType::SCENE_2D);

    sm->playBGM(static_cast<TCHAR*>(L"data/test.wav"));

    m_pSprite = new JCS_D3DX_v11_Engine::Sprite2D(
        dm->GetDriectX3D_v11_DeviceAsRef(), 
        L"Sprite/normal/swingTF_1.png", 1000, 500);


    m_pFont = new JCS_D3DX_v11_Engine::Font2D(dm->GetDriectX3D_v11_DeviceAsRef(), L"Font/Arial.spritefont");

    m_pAnimation = new JCS_D3DX_v11_Engine::Animation2D(L"Character.jcs/normal_data", L"walk1", dm->GetDriectX3D_v11_DeviceAsRef());



    m_pInterface = new JCS_D3DX_v11_Engine::Interface2D(dm->GetDriectX3D_v11_DeviceAsRef());
    m_pInterface->AddRenderableObject(m_pFont);
    m_pInterface->AddRenderableObject(m_pSprite);
    
    return true;
}

void DirectX11_Game::Run(float deltaTime)
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


void DirectX11_Game::Update(float deltaTime)
{
    if (im->getKeyboard()->KeyIsPressed(VK_DELETE)) 
        sm->playCompleteShot((TCHAR*)L"data/sound01.wav");
}

void DirectX11_Game::Draw(float deltaTime)
{
    dm->GetDriectX3D_v11_DeviceAsRef().Clear(DirectX::Colors::BlueViolet);
    dm->GetDriectX3D_v11_DeviceAsRef().ClearDepth();

    // do 3D rendering on the back buffer here

    m_pInterface->draw();

    m_pAnimation->DrawAnimation(m_pInterface->GetSpriteBatchRef(), true);

    dm->GetDriectX3D_v11_DeviceAsRef().RenderPresent();
}

