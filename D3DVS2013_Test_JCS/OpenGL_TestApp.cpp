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

    if (!JCS_SDL_Engine::Application::Initialize())
        return false;

    m_pGame = new OpenGL_Game(
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


