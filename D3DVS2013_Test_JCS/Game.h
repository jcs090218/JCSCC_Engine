#ifndef _GAME_H
#define _GAME_H

#include "StdAfx.h"

#include <GameTool_JCS\GameTool_StdAfx.h>
#include <GameTool_JCS\SoundManager.h>
#include <GameTool_JCS\GameManager.h>
#include <GameTool_JCS\InputManager.h>
#include <GameTool_JCS\DeviceManager.h>
#include <GameTool_JCS\SceneManager.h>

#include <GameTool_JCS\GameTimer.h>

#include <Direct_2D_Framework_JCS\Sprite2D.h>

#include <Direct_2D_Framework_JCS\Capsule2D.h>
#include <Direct_2D_Framework_JCS\Circle2D.h>
#include <Direct_2D_Framework_JCS\Hexagon2D.h>
#include <Direct_2D_Framework_JCS\Rectangle2D.h>
#include <Direct_2D_Framework_JCS\Polygon2D.h>
#include <Direct_2D_Framework_JCS\Shape2D.h>



//using namespace JCS_D3DX_v9_Engine;
//using namespace JCS_D2DEngine;
//using namespace JCS_GameTool;

class Game
{
private:
    // Managers
    static JCS_GameTool::GameManager* gm;	//
    static JCS_GameTool::SoundManager* sm;	// for sound
    static JCS_GameTool::InputManager* im;
    static JCS_GameTool::DeviceManager* dm;
    static JCS_GameTool::SceneManager* sem;

    //-- In the scene
    JCS_D2DEngine::Sprite2D* testSprite2D;
    JCS_D2DEngine::GameObject2D* rect;
    JCS_D2DEngine::GameObject2D* rect2;
    JCS_D2DEngine::GameObject2D* circle;
    JCS_D2DEngine::GameObject2D* circle2;
    JCS_D2DEngine::GameObject2D* capsule;
    JCS_D2DEngine::GameObject2D* capsule2;
    JCS_D2DEngine::GameObject2D* m_pHexagon;

    GameTimer* m_pGameTimer;

    // Variables
    float speedX, speedY;		// players x and y position
    float mainSpeed = 180;

public:
	// Constructor and Destructor
    Game(JCS_GameInput::KeyboardServer* kServer, JCS_GameInput::MouseServer* mServer, GameTimer* mTimer);
	virtual ~Game();
	
	// Game Functions
	bool Initlialize(HWND hWnd);
	void Run(float deltaTime);
	void Update(float deltaTime);
	void Draw(float deltaTime);

    void SetGamePad(JCS_Input* pInput) { im->setInput(pInput); }

};


#endif	// _GAME_H
