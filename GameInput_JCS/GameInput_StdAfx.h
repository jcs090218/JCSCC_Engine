/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

// GameInput_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __GAMEINPUT_STDAFX_H__
#define __GAMEINPUT_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>


#ifdef _WIN32

//-- XInput --//
#include <xinput.h>

#endif // _WIN32

////// LINKER ////////////////
#ifdef _WIN32
#pragma comment(lib, "xinput.lib")
#endif // _WIN32

#endif // __GAMEINPUT_STDAFX_H__

