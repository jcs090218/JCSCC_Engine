/**
 * $File: OpenGL_TestApp.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "OpenGL_TestApp.h"


OpenGL_TestApp::OpenGL_TestApp()
    : m_pGame(nullptr)
{

}

OpenGL_TestApp::~OpenGL_TestApp()
{
    SafeDeleteObject(m_pGame);
}

bool OpenGL_TestApp::Initialize()
{
    // We want to see framerate than set it to true
    ShowFrameRate(true);

	// NOTE(jenchieh): window dependency?
	//SetWindowIndependent(true);

    if (!JCS_SDL_Engine::Application::Initialize())
        return false;

	CreateSubWindow("Inspector", 20, 20, 800, 600, JCS_SDL_Engine::FULLSCREEN);
	CreateSubWindow("Console", 800, 200, JCS_SDL_Engine::FULLSCREEN);

    m_pGame = new OpenGL_Game(this, 
        JCS_SDL_Engine::Application::GetMouseRef(), 
        JCS_SDL_Engine::Application::GetKeyboardRef());

    if (!m_pGame->Initialize())
        return false;

    return true;
}

void OpenGL_TestApp::RunApp(float deltaTime)
{
    m_pGame->Run(deltaTime);
}


