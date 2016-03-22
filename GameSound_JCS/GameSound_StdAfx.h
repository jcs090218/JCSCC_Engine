// GameSound_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __GAMESOUND_STDAFX_H__
#define __GAMESOUND_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

#ifdef _WIN32

//-- DirectSound --//
#include <dsound.h>

//-- DirectShow --//
#include <dshow.h>

//-- DirectMusic --//
#include <dmksctrl.h>
#include <dmusicc.h>

//-- FMOD --//
#include "FMOD\include\fmod.hpp"

#endif // _WIN32


////// Local Header Files /////////
#include "JCS_SoundAPI.h"


////// LINKER ////////////////
#ifdef _WIN32
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "fmodex_vc.lib")  // fmod library
#endif // _WIN32

#endif // __GAMESOUND_STDAFX_H__

