#ifndef __JCS_INPUT_H__
/**
 * $File: JCS_Input.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_INPUT_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //====================================================================================
    // Name : JCS_Input (Interface)
    //
    // Description : interface for all the input sub-classes.
    //====================================================================================
    class JCS_Input
    {
    public:
        virtual ~JCS_Input() { }
    };
}

typedef JCS_GameInterface::JCS_Input JCS_Input;

#endif // __JCS_INPUT_H__

