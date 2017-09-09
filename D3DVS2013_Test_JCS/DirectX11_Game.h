#ifndef __DIRECTX11_GAME_H__
/**
 * $File: DirectX11_Game.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __DIRECTX11_GAME_H__

#include <GameInput_JCS\DirectInput\Keyboard.h>
#include <GameInput_JCS\DirectInput\Mouse.h>

#include <GameTool_JCS\GameManager.h>
#include <GameTool_JCS\InputManager.h>
#include <GameTool_JCS\SoundManager.h>
#include <GameTool_JCS\SceneManager.h>
#include <GameTool_JCS\DeviceManager.h>

#include <DirectX_3D_v11_Framework_JCS\Interface2D.h>
#include <DirectX_3D_v11_Framework_JCS\Sprite2D.h>
#include <DirectX_3D_v11_Framework_JCS\Font2D.h>

#include <DirectX_3D_v11_Framework_JCS\Animation2D.h>


class DirectX11_Game
{
private:
    JCS_GameTool::GameManager* gm;
    JCS_GameTool::SoundManager* sm;
    JCS_GameTool::InputManager* im;
    JCS_GameTool::DeviceManager* dm;
    JCS_GameTool::SceneManager* sem;


    JCS_D3DX_v11_Engine::Interface2D* m_pInterface;
    JCS_D3DX_v11_Engine::RenderableObject* m_pSprite;
    JCS_D3DX_v11_Engine::RenderableObject* m_pFont;

    JCS_D3DX_v11_Engine::Animation2D* m_pAnimation;

public:
    DirectX11_Game(JCS_GameInput::KeyboardServer* kServer, JCS_GameInput::MouseServer* mServer);
    virtual ~DirectX11_Game();

    bool Initlialize(HWND hWnd);
    void Run(float deltaTime);
    
    void Update(float deltaTime);
    void Draw(float deltaTime);

};

#endif // __DIRECTX11_GAME_H__

