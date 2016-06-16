/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_INPUT_H__
#define __JCS_INPUT_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // Name : JCS_Input (Interface)
    //
    // Desc : interface for all the input sub-classes.
    //------------------------------------------------------------------------------------
    class JCS_Input
    {
    public:
        virtual ~JCS_Input() { }
    };
}

typedef JCS_GameInterface::JCS_Input JCS_Input;

#endif // __JCS_INPUT_H__

