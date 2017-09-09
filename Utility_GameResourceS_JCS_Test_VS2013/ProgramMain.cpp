/**
 * $File: ProgramMain.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#define _JCSVLD

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

