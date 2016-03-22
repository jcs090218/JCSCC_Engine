#ifndef __OPENGL_TESTAPP_H__
#define __OPENGL_TESTAPP_H__

#include <SDL_Framework_JCS\Application.h>
#include  "OpenGL_Game.h"

class OpenGL_TestApp
    : public JCS_SDL_Engine::Application
{
public:
    OpenGL_TestApp();
    virtual ~OpenGL_TestApp();

    OpenGL_Game* m_pGame;

    virtual bool Initialize() override;

protected:
    virtual void RunApp(float gameTime) override;
};

#endif // __OPENGL_TESTAPP_H__

