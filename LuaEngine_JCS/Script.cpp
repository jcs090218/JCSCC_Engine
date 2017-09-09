/**
 * $File: Script.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Script.h"

#include "Helpers.h"
#include "LuaEngine.h"
#include <initializer_list>

namespace JCS_LuaEngine
{
    Script::Script(const std::string scriptsource, LuaEngine& engine)
        : m_luaEngine(engine)
        , m_source(scriptsource)
        , on_create(m_luaEngine.getState())
        , on_destroy(m_luaEngine.getState())
        , on_update(m_luaEngine.getState())
    {

    }

    Script::~Script()
    {

    }

    void Script::compile()
    {
        m_luaEngine.RunScript(m_source.c_str());

        on_create = luabridge::getGlobal(m_luaEngine.getState(), "on_create");
        on_destroy = luabridge::getGlobal(m_luaEngine.getState(), "on_destroy");
        on_update = luabridge::getGlobal(m_luaEngine.getState(), "on_update");
    }

    void Script::initialize()
    {
        if (on_create.isFunction())
        {
            try
            {
                
            }
            catch (LuaException& e)
            {
                IXLOG("INIT: Lua Error: ", LOG_ERROR, false);
                IXLOG(e.what(), LOG_PLAIN, true);
            }
        }
    }

    void Script::update(float32 delta)
    {
        if (on_update.isFunction())
        {
            try
            {
                
            }
            catch (LuaException &e)
            {
                IXLOG("UPDATE: Lua Error: ", LOG_ERROR, false);
                IXLOG(e.what(), LOG_PLAIN, true);
            }
        }
    }

    void Script::destroy()
    {
        if (on_destroy.isFunction())
        {
            try
            {
                
            }
            catch (LuaException &e)
            {
                IXLOG("DESTROY: Lua Error: ", LOG_ERROR, false);
                IXLOG(e.what(), LOG_PLAIN, true);
            }
        }
    }

}

