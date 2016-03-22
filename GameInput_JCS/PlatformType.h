#ifndef __PLATFORMTYPE_H__
#define __PLATFORMTYPE_H__


namespace JCS_GameInput
{
    //------------------------------------------------------------------------------------
    // Name : PlatformType 
    //
    // Desc : organize all the platform here.
    //------------------------------------------------------------------------------------
    enum class PlatformType
    {
        PC,             // PC
        PS,             // PlayStation
        PS2,            // PlayStation 2
        PS3,            // PlayStation 3
        PS4,            // PlayStation 4
        XBOX360,        // XBox 360
        XBOXONE         // XBox One
    };
}

typedef JCS_GameInput::PlatformType PlatformType;

#endif // __PLATFORMTYPE_H__

