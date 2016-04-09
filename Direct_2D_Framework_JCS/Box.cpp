/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Box.h"


#include "Rectangle2D.h"

namespace JCS_D2DEngine
{
    Box::Box()
        : m_rect(nullptr)
        ,m_body(nullptr)
        , m_fixture(nullptr)
    {

    }

    Box::~Box()
    {
        SafeDeleteObject(m_rect);
    }

    void Box::initialize(b2World& world, const JCS_VECTOR2F& position, const JCS_VECTOR2F& dimension)
    {
        // Make the body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(position.x, position.y);
        m_body = world.CreateBody(&bodyDef);

        b2PolygonShape boxShape;
        boxShape.SetAsBox(dimension.x / 2.0f, dimension.y / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &boxShape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        m_fixture = m_body->CreateFixture(&fixtureDef);
    }

}

