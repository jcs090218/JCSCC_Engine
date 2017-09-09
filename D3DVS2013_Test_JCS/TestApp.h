#ifndef __TESTAPP_H__
/**
 * $File: TestApp.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __TESTAPP_H__


#include <GameTool_JCS\Application.h>

class Game;

class TestApp : public JCS_GameTool::Application
{
private:
    Game* m_pGame;

public:
    TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    virtual ~TestApp();

    virtual bool Initialize() override;

protected:
    virtual void RunApp(float deltaTime) override;
};

#endif // __TESTAPP_H__

