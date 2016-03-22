#ifndef __TESTGAME_H__
#define __TESTGAME_H__

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

class TestGame
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
    TestGame(KeyboardServer* kServer, MouseServer* mServer);
    ~TestGame();


    bool Initialize(HWND hWnd);
    void Run(float gameTime);

    void Update(float gameTime);
    void Draw();
};

#endif // __TESTGAME_H__

