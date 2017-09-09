/**
 * $File: LuaEngine.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "LuaEngine.h"

#include "Helpers.h"

namespace JCS_LuaEngine
{
    LuaEngine::LuaEngine()
        : m_luaState(luaL_newstate())
    {
        luaL_openlibs(m_luaState);
    }

    LuaEngine::~LuaEngine()
    {
        lua_close(m_luaState);
    }

    void LuaEngine::err_report(int state)
    {
        if (state != 0)
        {
            IXLOG("SCRIPT: Lua Error: ", LOG_ERROR, false);
            IXLOG(lua_tostring(m_luaState, state), LOG_PLAIN, true);

            lua_pop(m_luaState, 1);
            std::exit(-1);
        }
    }

    void LuaEngine::RunScript(const char* filename)
    {
        std::string f(filename);
        if (f.empty())
            return;
        int state = luaL_dofile(m_luaState, filename);
        err_report(state);
    }

    void LuaEngine::RunString(const char* expr)
    {
        if (expr == nullptr)
        {
            IXLOG("Error: ", LOG_ERROR, false);
            IXLOG("Null expression is not allowed.", LOG_PLAIN, true);

            std::exit(-1);
        }
        int state = luaL_dostring(m_luaState, expr);
        err_report(state);
    }

}

