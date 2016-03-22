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

