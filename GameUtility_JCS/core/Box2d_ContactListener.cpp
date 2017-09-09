/**
 * $File: Box2d_ContactListener.cpp $
 * $Date: 2016-12-06 22:26:50 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../GameUtility_JCS.h"

namespace JCS_GameUtil
{

    void DestructionListener::SayGoodbye(b2Joint* joint)
    {
        if (test->m_mouseJoint == joint)
        {
            test->m_mouseJoint = NULL;
        }
        else
        {
            test->JointDestroyed(joint);
        }
    }

    Box2d_ContactListener::Box2d_ContactListener()
        : m_contacts()
    {
        b2Vec2 gravity;
        gravity.Set(0.0f, -9.81f);
        m_pWorld = new b2World(gravity);
        m_bomb = NULL;
        m_textLine = 30;
        m_mouseJoint = NULL;
        m_pointCount = 0;

        m_destructionListener.test = this;
        m_pWorld->SetDestructionListener(&m_destructionListener);
        m_pWorld->SetContactListener(this);
        //m_pWorld->SetDebugDraw(&g_debugDraw);

        m_bombSpawning = false;

        m_stepCount = 0;

        b2BodyDef bodyDef;
        m_pGroundBody = m_pWorld->CreateBody(&bodyDef);

        memset(&m_maxProfile, 0, sizeof(b2Profile));
        memset(&m_totalProfile, 0, sizeof(b2Profile));
    }

    Box2d_ContactListener::~Box2d_ContactListener()
    {
        SafeDeleteObject(m_pWorld);
    }

    void Box2d_ContactListener::BeginContact(b2Contact* contact)
    {
        // We need to copy out the data because the b2Contact passed in
        // is reused.
        ContactPoint myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
        m_contacts.push_back(myContact);
    }

    void Box2d_ContactListener::EndContact(b2Contact* contact)
    {
        ContactPoint myContact = { contact->GetFixtureA(), contact->GetFixtureB() };

        std::vector<ContactPoint>::iterator pos;
        pos = std::find(m_contacts.begin(), m_contacts.end(), myContact);

        if (pos != m_contacts.end())
        {
            m_contacts.erase(pos);
        }
    }

    void Box2d_ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
    {
        const b2Manifold* manifold = contact->GetManifold();

        if (manifold->pointCount == 0)
        {
            return;
        }

        b2Fixture* fixtureA = contact->GetFixtureA();
        b2Fixture* fixtureB = contact->GetFixtureB();

        b2PointState state1[b2_maxManifoldPoints], state2[b2_maxManifoldPoints];
        b2GetPointStates(state1, state2, oldManifold, manifold);

        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);

        for (int32 index = 0; 
            index < manifold->pointCount && m_pointCount < k_maxContactPoints;
            ++index)
        {
            ContactPoint* cp = m_points + m_pointCount;
            cp->fixtureA = fixtureA;
            cp->fixtureB = fixtureB;
            cp->position = worldManifold.points[index];
            cp->normal = worldManifold.normal;
            cp->state = state2[index];
            cp->normalImpulse = manifold->points[index].normalImpulse;
            cp->tangentImpulse = manifold->points[index].tangentImpulse;
            cp->separation = worldManifold.separations[index];
            ++m_pointCount;
        }
    }

    void Box2d_ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
    {

    }
}
