/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

/**
 * $File: PlatformInputFactory.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "PlatformInputFactory.h"


#include "XInput\GamePad.h"

namespace JCS_GameInput
{
    JCS_Input* PlatformInputFactory::CreatePlatformInput(PlatformType type)
    {
        JCS_Input* input = nullptr;

        switch (type)
        {
         // PC
        case PlatformType::PC: 
        { 
            // no Gamepad for PC
            input = nullptr; 
        } break;

        // PlayStation (Sony)
        case PlatformType::PS: 
        {
            input = nullptr; 
        } break;
        case PlatformType::PS2: 
        { 
            input = nullptr; 
        } break;
        case PlatformType::PS3: 
        { 
            input = nullptr; 
        } break;
        case PlatformType::PS4: 
        { 
            input = nullptr; 
        } break;

        // XBox (Microsoft)
        case PlatformType::XBOXONE:     // [NOTE] not sure about this yet...
        case PlatformType::XBOX360: 
        { 
            // XInput for XBox 360
            input = new GamePad();

            // Try to load the dll file
            dynamic_cast<GamePad*>(input)->LoadXInput();

        } break;
        }

        return input;
    }

}

