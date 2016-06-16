/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_COLLISION_H__
#define __JCS_COLLISION_H__

#include "JCS_Component.h"

namespace JCS_GameInterface
{

    //--------------------------------------------------------------------------------------------
    // JCS_Component
    // 
    // Desc : Interface of all Collision
    //--------------------------------------------------------------------------------------------
    struct JCS_Collision
        : JCS_Component
    {
        virtual ~JCS_Collision() { }

        virtual void Update() = 0;

        // make sure do not draw the line in play mode
        virtual void Draw() = 0;
    };
    
}

typedef JCS_GameInterface::JCS_Collision JCS_Collision;

#endif // __JCS_COLLISION_H__
