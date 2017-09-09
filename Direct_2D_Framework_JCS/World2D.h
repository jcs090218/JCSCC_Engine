#ifndef __D2D_WORLD2D_H__
/**
 * $File: World2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D2D_WORLD2D_H__


#include "D2D_StdAfx.h"

#include <GameInterface_JCS\JCS_World.h>

namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : World2D
    //
    // Description : Sandbox in 2d world.
    //====================================================================================
    class World2D
        : public JCS_World
    {
    private:
        std::unique_ptr<b2World> m_pPhysicWorld;

    public:
        explicit World2D(bool isPhysicWolrd = false, float32 xGrav = 0.0f, float32 yGrav = -9.81f);
        ~World2D();

        /** setter **/

        /** getter **/
        b2World* GetPhysicWorld() const { return this->m_pPhysicWorld.get(); }

    private:
        void CreatePhysicWorld(bool isPhysicWolrd, float32 xGrav, float32 yGrav);
    };

}

#endif // __D2D_WORLD2D_H__

