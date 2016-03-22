#ifndef __SCRIPT_H__
#define __SCRIPT_H__


#include "LuaEngine_StdAfx.h"

namespace JCS_LuaEngine
{
    class LuaEngine;

    class Script
    {
    private:
        LuaEngine& m_luaEngine;
        std::string m_source;

        luabridge::LuaRef on_create;
        luabridge::LuaRef on_destroy;
        luabridge::LuaRef on_update;

    public:
        explicit Script(const std::string scriptsource, 
                        LuaEngine& engine);
        ~Script();

        void compile();
        void initialize();
        void update(float32 delta);
        void destroy();

        // setter

        // getter
        std::string GetSource() const { return this->m_source; }
        LuaEngine& GetLuaEngineRef() const { return this->m_luaEngine; }
    };

}

#endif // __SCRIPT_H__

