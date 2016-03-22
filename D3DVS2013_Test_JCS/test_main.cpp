#define _JCS_VLD

// Platform for specific Devices
//#define __OPENGL__
//#define __DIRECT2D__
#define __DIRECTX3D__
//#define __ALLEGRO__

//--------------------------------------------------------------
// Using Direct2D
//--------------------------------------------------------------
#ifdef __DIRECT2D__

#include "TestApp.h"

//WinMain function, set up window and message loop.
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
	
	// 初始話程式...
	if (app.Initialize())
		return app.Run();

	return EXIT_SUCCESS;
}

#endif 

//--------------------------------------------------------------
// Using OpenGL
//--------------------------------------------------------------
#ifdef __OPENGL__

#include <OpenGL_Framework_JCS\OpenGL_StdAfx.h>
#include <SDL_Framework_JCS\SDL_StdAfx.h>
#include "OpenGL_TestApp.h"

#include <iostream>

#undef main

int main(int argc, char** argv)
{
    OpenGL_TestApp opengl_app;

    if (opengl_app.Initialize())
        opengl_app.Run();

	return 0;
}

#endif 

//--------------------------------------------------------------
// Using DirectX3D
//--------------------------------------------------------------
#ifdef __DIRECTX3D__

#include "DirectX3D_TestApp.h"

int WINAPI
WinMain(HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPSTR lpCmdLine,
int nCmdShow)
{
    DirectX3D_TestApp app(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);

    // 初始話程式...
    if (app.Initialize())
        return app.Run();

    return EXIT_SUCCESS;
}

#endif 

//--------------------------------------------------------------
// Using Allegro
//--------------------------------------------------------------
#ifdef __ALLEGRO__

#include <Allegro_Framework_JCS\Allegro_StdAfx.h>

int main()
{
    ALLEGRO_DISPLAY* display;

    if (!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5.0.10", NULL, NULL);
        return EXIT_FAILURE;
    }

    display = al_create_display(800, 600);

    if (!display)
    {
        al_show_native_message_box(NULL, NULL, NULL, "Could not create Allegro Window", NULL, NULL);
        return EXIT_FAILURE;
    }

    al_destroy_display(display);

    return EXIT_SUCCESS;
}

#endif // __ALLEGRO__

