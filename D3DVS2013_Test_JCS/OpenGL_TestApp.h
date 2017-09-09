#ifndef __OPENGL_TESTAPP_H__
/**
 * $File: OpenGL_TestApp.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
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
    virtual void RunApp(float deltaTime) override;
};

#endif // __OPENGL_TESTAPP_H__

