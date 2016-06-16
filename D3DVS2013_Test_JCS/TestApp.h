#ifndef __TESTAPP_H__
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

