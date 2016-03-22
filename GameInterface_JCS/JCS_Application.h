#ifndef __JCS_APPLICATION_H__
#define __JCS_APPLICATION_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // JCS_Application (Interface)
    //
    // Desc : interface for all the application sub-classes.
    //------------------------------------------------------------------------------------
    class JCS_Application
    {
    public:
        virtual ~JCS_Application() { }

    protected:
        virtual bool Initialize() = 0;
        virtual void RunApp(float32 gameTime) = 0;
    };
}

typedef JCS_GameInterface::JCS_Application JCS_Application;

#endif // __JCS_APPLICATION_H__

