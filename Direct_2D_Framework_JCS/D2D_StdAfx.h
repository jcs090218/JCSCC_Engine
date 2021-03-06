#ifndef __D2D_STDAFX_H__
/**
 * $File: D2D_StdAfx.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D2D_STDAFX_H__

 // D2D_StdAfx.cpp.h : include file for standard system include files,
 //  or project specific include files that are used frequently, but
 //      are changed infrequently
 //


#include <GameTool_JCS\GameTool_StdAfx.h>

#ifdef _WIN32
// d2d1.h is needed for the Direct2D Logic
#include <d2d1.h>
#include <wincodec.h>    // WIC codec header for decoding image from file (Must be on top of <d2d1.h>)

////// LINKER ////////////////
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")
#endif // _WIN32

////// Local Headers ////////////////
#include "D2D_CrashReason.h"

#undef min
#undef max

// 物理引擎的變數
#define FREE_FALL_ACCELERATION 9.8f
#define MaxPolyVertexCount 64

////// DEBUGGING ////////////////
//#define _JCS_DEBUG_2D


#endif // __D2D_STDAFX_H__
