#ifndef __OPENGL_GAME_H__
/**
 * $File: OpenGL_Game.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __OPENGL_GAME_H__

#include <SDL_Framework_JCS\Window.h>
#include <SDL_Framework_JCS\Application.h>
#include <GameTool_JCS\GameTimer.h>

#include "StdAfx.h"

#include <GameTool_JCS\GameManager.h>
#include <SDL_Framework_JCS\Mouse.h>
#include <SDL_Framework_JCS\Keyboard.h>
#include <GameSound_JCS\SDL_Mixer\SDL_Mixer_AudioEngine.h>

class OpenGL_Game
{
private:
	JCS_GameTool::GameManager* gm;    // 

	JCS_SDL_Engine::Mouse& m_mouse;
	JCS_SDL_Engine::Keyboard& m_kbd;
	JCS_GameSound::SDL_Mixer_AudioEngine m_audioEngine;
	FMOD::System* m_fmodSystem;
	FMOD::Sound* sound1, *sound2;

	JCS_SDL_Engine::Application* m_app = nullptr;

	JCS_SDL_Engine::SDL_Sprite* m_pSprite = nullptr;

public:
	OpenGL_Game(JCS_SDL_Engine::Application* app, JCS_SDL_Engine::Mouse& mouse, JCS_SDL_Engine::Keyboard& kbd);
	virtual ~OpenGL_Game();

	bool Initialize();
	void Run(float deltaTime);

private:
	void Update(float deltaTime);
	void Draw(float deltaTime);

};

#endif // __OPENGL_GAME_H__
