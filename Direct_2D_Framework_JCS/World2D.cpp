#include "World2D.h"


namespace JCS_D2DEngine
{
    World2D::World2D(bool isPhysicWolrd, float32 xGrav, float32 yGrav)
        : m_pPhysicWorld()
    {
        CreatePhysicWorld(isPhysicWolrd, xGrav, yGrav);
    }

    World2D::~World2D()
    {

    }

    // Create Physic World
    void World2D::CreatePhysicWorld(bool isPhysicWolrd, float32 xGrav, float32 yGrav)
    {
        if (!isPhysicWolrd)
            return;
        
        b2Vec2 gravity(xGrav, yGrav);
        m_pPhysicWorld = std::make_unique<b2World>(gravity);
    }

}

