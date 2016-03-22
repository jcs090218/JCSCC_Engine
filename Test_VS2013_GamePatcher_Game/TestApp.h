#ifndef __TESTAPP_H__
#define __TESTAPP_H__


#include <GameTool_JCS\Application.h>

class TestGame;

class TestApp
    : public JCS_GameTool::Application
{
private:
    TestGame* m_pGame = nullptr;

public:
    TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    virtual ~TestApp();

    virtual bool Initialize() override;

protected:
    virtual void RunApp(float gameTime) override;
};

#endif // __TESTAPP_H__

