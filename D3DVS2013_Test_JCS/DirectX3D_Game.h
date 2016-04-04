#ifndef __DIRECTX3D_GAME_H__
#define __DIRECTX3D_GAME_H__

#include <GameInput_JCS\DirectInput\Keyboard.h>
#include <GameInput_JCS\DirectInput\Mouse.h>

#include <GameTool_JCS\GameManager.h>
#include <GameTool_JCS\InputManager.h>
#include <GameTool_JCS\SoundManager.h>
#include <GameTool_JCS\SceneManager.h>
#include <GameTool_JCS\DeviceManager.h>

#include <DirectX_3D_v9_Framework_JCS\D3DX_v9_StdAfx.h>
#include <DirectX_3D_v9_Framework_JCS\GameObject3D.h>
#include <DirectX_3D_v9_Framework_JCS\DisplayObject.h>

class DirectX3D_Game
{
private:
    JCS_GameTool::GameManager* gm;
    JCS_GameTool::SoundManager* sm;
    JCS_GameTool::InputManager* im;
    JCS_GameTool::DeviceManager* dm;
    JCS_GameTool::SceneManager* sem;

    JCS_D3DX_v9_Engine::GameObject3D* player;
    JCS_D3DX_v9_Engine::DisplayObject* testSprite;
    JCS_D3DX_v9_Engine::DisplayObject* testAnimation;

    // 3D test
    /*LPD3DXMESH meshTeapot;*/

    // Variables
    float speedX, speedY;		// players x and y position
    float mainSpeed = 180;

    void update(float deltaTime);

public:
    DirectX3D_Game(JCS_GameInput::KeyboardServer* kServer, JCS_GameInput::MouseServer* mServer);
    virtual ~DirectX3D_Game();

    bool Initlialize(HWND hWnd);
    void Run(float deltaTime);

    void Update(float deltaTime);
    void Draw(float deltaTime);


};

#endif // __DIRECTX3D_GAME_H__

