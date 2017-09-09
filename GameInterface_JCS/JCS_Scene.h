#ifndef __JCS_SCENE_H__
/**
 * $File: JCS_Scene.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_SCENE_H__


#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //====================================================================================
    // JCS_Scene (Interface)
    //
    // Description : interface for all the scene sub-classes.
    //====================================================================================
    struct JCS_Scene
    {
        virtual ~JCS_Scene() { }

        virtual void initialize() = 0;
        virtual void update(float32 deltaTime) = 0;
        virtual void draw() = 0;
    };

}

typedef JCS_GameInterface::JCS_Scene JCS_Scene;

#endif // __JCS_SCENE_H__

