#ifndef __D3DX_V9_STDAFX_H__
/**
 * $File: D3DX_v9_StdAfx.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2014 by Shen, Jen-Chieh $
 */
#define __D3DX_V9_STDAFX_H__

// D3DX_v9+StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//


#include <GameTool_JCS\GameTool_StdAfx.h>

#ifdef _WIN32
// Direct3D Version 9
#include <d3d9.h>
#include <DirectX_3D_v9_Framework_JCS\DirectX SDK\include\d3dx9.h>

////// LINKER ////////////////
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#endif // _WIN32

////// Local Headers ////////////////
#include "D3D9_CrashReason.h"

#endif // __D3DX_V9_STDAFX_H__

