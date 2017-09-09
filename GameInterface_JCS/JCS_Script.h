#ifndef __JCS_SCRIPT_H__
/**
 * $File: JCS_Script.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_SCRIPT_H__


#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //====================================================================================
    // JCS_Script (Interface)
    //
    // Description : interface for all the script sub-classes.
    //====================================================================================
    struct JCS_Script
    {
        virtual ~JCS_Script() { }

        // Script in C++ only!
        virtual void update(float32 deltaTime) = 0;

        // Scripting Language not in C++, 
        // this will loaded from the script so no delta time involved.
        virtual void Update() { /* optional */ }
    };

}

typedef JCS_GameInterface::JCS_Script JCS_Script;

#endif // __JCS_SCRIPT_H__

