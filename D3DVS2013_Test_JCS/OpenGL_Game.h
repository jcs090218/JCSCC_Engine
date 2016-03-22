#ifndef __OPENGL_GAME_H__
#define __OPENGL_GAME_H__

#include <SDL_Framework_JCS\Window.h>
#include <GameTool_JCS\GameTimer.h>

#include "StdAfx.h"

#include <GameTool_JCS\GameManager.h>
#include <SDL_Framework_JCS\Mouse.h>
#include <SDL_Framework_JCS\Keyboard.h>
#include <GameSound_JCS\SDL_Mixer\SDL_Mixer_AudioEngine.h>

class OpenGL_Game
{
private:
    JCS_GameTool::GameManager* gm;	// 

    JCS_SDL_Engine::Mouse& m_mouse;
    JCS_SDL_Engine::Keyboard& m_kbd;
    JCS_GameSound::SDL_Mixer_AudioEngine m_audioEngine;
    FMOD::System* m_fmodSystem;
    FMOD::Sound* sound1, *sound2;

public:
    OpenGL_Game(JCS_SDL_Engine::Mouse& mouse, JCS_SDL_Engine::Keyboard& kbd);
	virtual ~OpenGL_Game();

    bool Initialize();
	void Run(float gameTime);

private:
    void Update(float gameTime);
    void Draw(float gameTime);

};

#endif // __OPENGL_GAME_H__

