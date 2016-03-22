#ifndef __JCS_SCENE_H__
#define __JCS_SCENE_H__


#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // JCS_Scene (Interface)
    //
    // Desc : interface for all the scene sub-classes.
    //------------------------------------------------------------------------------------
    struct JCS_Scene
    {
        virtual ~JCS_Scene() { }

        virtual void initialize() = 0;
        virtual void update(float32 gameTime) = 0;
        virtual void draw() = 0;
    };

}

typedef JCS_GameInterface::JCS_Scene JCS_Scene;

#endif // __JCS_SCENE_H__

