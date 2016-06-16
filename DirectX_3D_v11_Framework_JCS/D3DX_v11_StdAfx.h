/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

// D3DX_v11_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __D3DX_V11_STDAFX_H__
#define __D3DX_V11_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

#ifdef _WIN32

// Direct3D Version 11
#include <d3d11.h>
#include <DirectX_3D_v9_Framework_JCS\DirectX SDK\include\d3dx11.h>

////// LINKER ////////////////
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")

#endif // _WIN32


////// Local Headers /////////////
#include "D3D11_CrashReason.h"


#endif // __D3DX_V11_STDAFX_H__
