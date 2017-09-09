/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GAMESOUND_STDAFX_H__
/**
 * $File: GameSound_StdAfx.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __GAMESOUND_STDAFX_H__

 // GameSound_StdAfx.h : include file for standard system include files,
 //  or project specific include files that are used frequently, but
 //      are changed infrequently
 //


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

