/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

// Allegro_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __ALLEGRO_STDAFX_H__
#define __ALLEGRO_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

// Allegro Version -> [ 5.0.10 ]
#include <Allegro_Framework_JCS\Allegro\include\allegro5\allegro.h>
#include <Allegro_Framework_JCS\Allegro\include\allegro5\allegro_native_dialog.h>


////// LINKER ////////////////
#ifdef _DEBUG
#pragma comment (lib, "allegro-5.0.10-monolith-md-debug.lib")
#else // Release
#pragma comment (lib, "allegro-5.0.10-monolith-md.lib")
#endif // _DEBUG


///// Local Header Files ////////////



#endif // __ALLEGRO_STDAFX_H__

