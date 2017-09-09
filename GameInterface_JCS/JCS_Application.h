#ifndef __JCS_APPLICATION_H__
/**
 * $File: JCS_Application.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_APPLICATION_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //====================================================================================
    // JCS_Application (Interface)
    //
    // Description : interface for all the application sub-classes.
    //====================================================================================
    class JCS_Application
    {
    public:
        virtual ~JCS_Application() { }

    protected:
        virtual bool Initialize() = 0;
        virtual void RunApp(float32 deltaTime) = 0;
    };
}

typedef JCS_GameInterface::JCS_Application JCS_Application;

#endif // __JCS_APPLICATION_H__

