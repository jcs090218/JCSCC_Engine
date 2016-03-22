#define _JCS_VLD

#include "TestApp.h"

int WINAPI
WinMain(HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPSTR lpCmdLine,
int nCmdShow)
{
    TestApp app(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);

    if (app.Initialize())
        return app.Run();

    return EXIT_SUCCESS;
}

