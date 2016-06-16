/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __PLATFORMINPUTFACTORY_H__
#define __PLATFORMINPUTFACTORY_H__


#include "GameInput_StdAfx.h"

#include "PlatformType.h"

namespace JCS_GameInput
{
    //------------------------------------------------------------------------------------
    // Name : PlatformInputFactory 
    //
    // Desc : Create Input Controller depends on platform type
    //------------------------------------------------------------------------------------
    class PlatformInputFactory
    {
    public:
        static JCS_Input* CreatePlatformInput(PlatformType type);

    };
}

typedef JCS_GameInput::PlatformInputFactory PlatformInputFactory;

#endif // __PLATFORMINPUTFACTORY_H__

