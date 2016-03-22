#ifndef __LUAENGINE_H__
#define __LUAENGINE_H__


#include "LuaEngine_StdAfx.h"

namespace JCS_LuaEngine
{
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

        // getter
        lua_State* getState() { return this->m_luaState; }
    };

}

#endif // __LUAENGINE_H__

