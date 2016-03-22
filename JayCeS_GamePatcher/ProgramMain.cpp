#define _JCS_VLD

#include "JayCeS_App.h"

int WINAPI
WinMain(HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPSTR lpCmdLine,
int nCmdShow)
{
    JayCeS_App app(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);

    if (app.Initialize())
        return app.Run();

    return EXIT_SUCCESS;
}


