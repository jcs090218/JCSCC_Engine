// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

//#include <dshow.h>		// 使用DirectX 中的 DirectShow組件

// microsoft os system
#define WM_GRAPHNOTIFY  WM_USER		// audio check WindowProc event use
#define WM_SOCKET 104

// Client's / Server's INFO
#define HOST_NAME "127.0.0.1"
#define PORT 5555

// 遊戲主程式INFO
#define WIDOW_TITLE L"Test_GamePatcher_Game"
#define WIDOW_CLASS L"Test Game Class"
#define SCREEN_WIDTH 1280		// set screen width
#define SCREEN_HEIGHT 720		// set screen height
#define FILL_VALUE 0x00		// color for D3D

////// LINKER ////////////////



#endif // __STDAFX_H__

