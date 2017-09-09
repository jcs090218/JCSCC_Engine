#ifndef __LUAENGINE_H__
/**
 * $File: LuaEngine.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __LUAENGINE_H__


#include "LuaEngine_StdAfx.h"

namespace JCS_LuaEngine
{

	//====================================================================================
	// Name : LuaEngine 
	//
	// Description : Lua Scripting Core Engine.
	//====================================================================================
    class LuaEngine
    {
    private:
        lua_State* m_luaState;
        void err_report(int state);

    public:
        LuaEngine();
        ~LuaEngine();

        void RunScript(const char* filename);
        void RunString(const char* expr);

        /** getter **/
        lua_State* getState() { return this->m_luaState; }
    };

}

#endif // __LUAENGINE_H__
