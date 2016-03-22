#ifndef __WORLD2D_H__
#define __WORLD2D_H__


#include "D2D_StdAfx.h"

#include <GameInterface_JCS\JCS_World.h>

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : World2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class World2D
        : public JCS_World
    {
    private:
        std::unique_ptr<b2World> m_pPhysicWorld;

    public:
        explicit World2D(bool isPhysicWolrd = false, float32 xGrav = 0.0f, float32 yGrav = -9.81f);
        ~World2D();

        // setter

        // getter
        b2World* GetPhysicWorld() const { return this->m_pPhysicWorld.get(); }

    private:
        void CreatePhysicWorld(bool isPhysicWolrd, float32 xGrav, float32 yGrav);
    };

}

#endif // __WORLD_H__

