#ifndef __DRIECTX3D_TESTAPP_H__
#define __DRIECTX3D_TESTAPP_H__

#include <GameTool_JCS\Application.h>
#include "DirectX3D_Game.h"
#include "DirectX11_Game.h"

// Warning Only use one of it
//#define DIRECTX_9
#define DIRECTX_11

class DirectX3D_TestApp
    : public JCS_GameTool::Application
{
private:
    DirectX3D_Game* m_pGame;
    DirectX11_Game* m_pGame11;

public:
    DirectX3D_TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    virtual ~DirectX3D_TestApp();

    virtual bool Initialize() override;

protected:
    virtual void RunApp(float gameTime) override;
};

#endif // __DRIECTX3D_TESTAPP_H__

