#ifndef __LUAENGINE_STDAFX_H__
/**
 * $File: LuaEngine_StdAfx.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __LUAENGINE_STDAFX_H__

 // LuaEngine_StdAfx.h : include file for standard system include files,
 //  or project specific include files that are used frequently, but
 //      are changed infrequently
 //


#include <GameTool_JCS\GameTool_StdAfx.h>


////// Lua Essential Files ////////////////
/// "Lua 5.3"
// Lua is written in C, so compiler needs to 
// know how to link its libraries
extern "C"
{
#include <LuaEngine_JCS\Lua\include\lua.hpp>
#include <LuaEngine_JCS\Lua\include\lua.h>
#include <LuaEngine_JCS\Lua\include\lauxlib.h>
#include <LuaEngine_JCS\Lua\include\lualib.h>
#include <LuaEngine_JCS\Lua\include\luaconf.h>
}

////// Libraries ////////////////
/// "LuaBridge" Library
#include <LuaEngine_JCS\LuaBridge\LuaBridge.h>
#include <LuaEngine_JCS\LuaBridge\detail\LuaException.h>

/// "Lua Wrapper" Library
#include <LuaEngine_JCS\Lua\include\luawrapper.hpp>
#include <LuaEngine_JCS\Lua\include\luawrapperutil.hpp>


// Local Header Files

////// LINKER ////////////////
#pragma comment (lib, "lua5.3.lib")


#endif // __LUAENGINE_STDAFX_H__

