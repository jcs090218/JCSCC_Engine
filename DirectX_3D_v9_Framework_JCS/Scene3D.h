/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SCENE3D_H__
#define __SCENE3D_H__

#include "D3DX_v9_StdAfx.h"

#include <GameInterface_JCS\JCS_Scene.h>


namespace JCS_D3DX_v9_Engine
{
    class Scene3D 
        : public JCS_Scene
    {
    private:


    public:
        Scene3D(bool isPhysicsWorld = false);
        ~Scene3D();

        virtual void initialize() override;
        virtual void update(float32 deltaTime) override;
        virtual void draw() override;

        // setter

        // getter

    };

}

#endif // __SCENE3D_H__

