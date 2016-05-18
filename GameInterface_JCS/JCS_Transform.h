/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_TRANSFORM_H__
#define __JCS_TRANSFORM_H__

#include "JCS_Component.h"

namespace JCS_GameInterface
{
    //-----------------------------------------------------------------------------------------------------------
    // JCS_Component
    // 
    // Desc : Interface of all Transform
    //-----------------------------------------------------------------------------------------------------------
    struct JCS_Transform
        : JCS_Component
    {
        virtual ~JCS_Transform() { }
    };

}

typedef JCS_GameInterface::JCS_Transform JCS_Transform;

#endif // __JCS_TRANSFORM_H__

