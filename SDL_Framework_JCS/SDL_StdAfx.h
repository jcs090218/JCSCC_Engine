/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

// SDL_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __SDL_STDAFX_H__
#define __SDL_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

#include <SDL_Framework_JCS\SDL\include\SDL.h>
#include <SDL_Framework_JCS\SDL\include\SDL_ttf.h>
#include <SDL_Framework_JCS\SDL\include\SDL_mixer.h>

// Local Header Files
#include "JCS_Errors.h"
#include "SDL_CrashReason.h"

#include "SDL_Animation.h"
#include "SDL_Sprite.h"
#include "SDL_Animator.h"

////// LINKER ////////////////
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

// SDL_image extension libraries
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")

#endif // __SDL_STDAFX_H__
