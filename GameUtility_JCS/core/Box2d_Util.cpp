/**
 * $File: Box2d_Util.cpp $
 * $Date: 2016-12-06 22:22:50 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../GameUtility_JCS.h"


namespace JCS_GameUtil
{

    Box2d_Util::Box2d_Util()
    {

    }

    Box2d_Util::~Box2d_Util()
    {

    }

    b2World* Box2d_Util::CreateWorld(JCS_GameInterface::JCS_VECTOR2F gravity, bool sleep /*= true*/)
    {
        // Define the gravity vector.
        b2Vec2 tmpGravity;
        tmpGravity.Set(gravity.x, gravity.y);

        // Do we want to let bodies sleep?
        bool doSleep = sleep;

        // Construct a world object, which will hold and simulate the rigid bodies.
        b2World* pWorld = new b2World(tmpGravity);
        pWorld->SetAllowSleeping(doSleep);

        return pWorld;
    }

    void Box2d_Util::CreateEdgeShape(
        b2World* world, 
        const float32 xPos,
        const float32 yPos,
        const b2Vec2& c1, 
        const b2Vec2& c2, 
        const b2BodyType type /*= b2_dynamicBody*/,
        const float32 density /*= 5.0f*/)
    {
        // create the shape type
        b2EdgeShape shape;
        shape.Set(c1, c2);

        // create the body
        b2BodyDef bd;
        bd.type = type;
        bd.position = b2Vec2(xPos, yPos);

        b2Body* body = world->CreateBody(&bd);

        // set the pyhsic info/setting
        body->CreateFixture(&shape, density);
    }

    void Box2d_Util::CreateRect(
        b2World* world,
        const float32 xPos,
        const float32 yPos,
        const float32 width,
        const float32 height,
        const b2BodyType type /*= b2_dynamicBody*/,
        const float32 density /*= 5.0f*/)
    {
        // create the shape type
        b2PolygonShape shape;
        shape.SetAsBox(width, height);

        // create the body
        b2BodyDef bd;
        bd.type = type;
        bd.position = b2Vec2(xPos, yPos);

        b2Body* body = world->CreateBody(&bd);

        // set the pyhsic info/setting
        body->CreateFixture(&shape, density);
    }

    void Box2d_Util::CreateCircle(
        b2World* world,
        const float32 xPos,
        const float32 yPos,
        const float32 radius,
        const b2BodyType type /*= b2_dynamicBody*/,
        const float32 density /*= 5.0f*/)
    {
        // create the shape type
        b2CircleShape shape;
        shape.m_radius = radius;

        // create the body
        b2BodyDef bd;
        bd.type = type;
        bd.position = b2Vec2(xPos, yPos);

        b2Body* body = world->CreateBody(&bd);

        // set the pyhsic info/setting
        body->CreateFixture(&shape, density);
    }

}
