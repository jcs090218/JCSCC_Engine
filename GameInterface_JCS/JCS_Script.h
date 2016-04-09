/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_SCRIPT_H__
#define __JCS_SCRIPT_H__


#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // JCS_Script (Interface)
    //
    // Desc : interface for all the script sub-classes.
    //------------------------------------------------------------------------------------
    struct JCS_Script
    {
        virtual ~JCS_Script() { }
    };

}

typedef JCS_GameInterface::JCS_Script JCS_Script;

#endif // __JCS_SCRIPT_H__

