#ifndef __JCS_TRANSFORM_H__
/**
 * $File: JCS_Transform.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_TRANSFORM_H__

#include "JCS_Component.h"

namespace JCS_GameInterface
{
    //====================================================================================-----------------------
    // JCS_Component
    // 
    // Description : Interface of all Transform
    //====================================================================================-----------------------
    struct JCS_Transform
        : JCS_Component
    {
        virtual ~JCS_Transform() { }
    };

}

typedef JCS_GameInterface::JCS_Transform JCS_Transform;

#endif // __JCS_TRANSFORM_H__

