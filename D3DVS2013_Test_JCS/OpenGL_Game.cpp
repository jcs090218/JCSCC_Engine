/**
 * $File: OpenGL_Game.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "OpenGL_Game.h"

#include "StdAfx.h"

OpenGL_Game::OpenGL_Game(
	JCS_SDL_Engine::Application* app, 
	JCS_SDL_Engine::Mouse& mouse, 
	JCS_SDL_Engine::Keyboard& kbd)
    : gm(nullptr)
    , m_mouse(mouse)
    , m_kbd(kbd)
	, m_app(app)
{

}

OpenGL_Game::~OpenGL_Game()
{
	JCS_GameTool::GameManager::DestroyInstance();
	SafeDeleteObject(m_pSprite);
}


bool OpenGL_Game::Initialize()
{
    gm = JCS_GameTool::GameManager::GetInstance();

    /*m_audioEngine.Initialize();

    JCS_GameSound::SDL_Mixer_Music music = m_audioEngine.LoadMusic("data/test.ogg");
    music.play(-1);*/

    // Initialize FMOD
    FMOD::System_Create(&m_fmodSystem); // create an instance of the game engine
    m_fmodSystem->init(32, FMOD_INIT_NORMAL, 0);

    //load sounds
    m_fmodSystem->createSound("data/test.wav", FMOD_HARDWARE, 0, &sound1);
    m_fmodSystem->createSound("data/sound01.wav", FMOD_HARDWARE, 0, &sound2);

    /* drumloop.wav has embedded loop points which 
      automatically makes looping turn on, 
      so turn it off here.  We could have also just put 
      FMOD_LOOP_OFF in the above CreateSound call. */
    sound1->setMode(FMOD_LOOP_OFF);
    sound2->setMode(FMOD_LOOP_OFF);

    m_fmodSystem->playSound(FMOD_CHANNEL_FREE, sound1, false, 0);

    glEnable(GL_DEPTH_TEST);    // check for depth

	m_pSprite = new JCS_SDL_Engine::SDL_Sprite();
	m_pSprite->LoadSprite("Sprite/PlayerPaper", ".png");

    return true;
}

void OpenGL_Game::Run(float deltaTime)
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

void OpenGL_Game::Update(float deltaTime)
{
    // TODO(JenChieh): Weird acting, if using isKeyDown we need to update, 
    //                 if using isKeyPressed cannot call "update()" function 
    //                 every frame...
    //m_kbd.update();


    if (m_mouse.GetMouseButtonDown())
    {
        glm::vec2 mouseCoords = m_mouse.GetMouseCoords();
        std::cout << mouseCoords.x << " " << mouseCoords.y << std::endl;
    }

	// window's input set.
	if (m_app->GetWindowByName("Inspector")->GetKeyboardPtr()->GetKeyDown(SDLK_d))
	{
		m_fmodSystem->playSound(FMOD_CHANNEL_FREE, sound2, false, 0);
	}


	// global input set.
	if (m_kbd.GetKey(SDLK_e))
	{
		m_fmodSystem->playSound(FMOD_CHANNEL_FREE, sound2, false, 0);
		std::cout << "ok\n";
	}

	m_fmodSystem->update();
}

void OpenGL_Game::Draw(float deltaTime)
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
