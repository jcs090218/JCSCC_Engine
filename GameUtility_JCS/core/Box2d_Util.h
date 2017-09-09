#ifndef __BOX2D_UTIL_H__
/**
 * $File: Box2d_Util.h $
 * $Date: 2016-12-06 22:22:46 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __BOX2D_UTIL_H__

#include "../GameUtility_JCS_StdAfx.h"

#include <GameInterface_JCS\JCS_GameType.h>

namespace JCS_GameUtil
{

    /**
    @class Box2d_Util
    @brief Handle Box2d library util.
    */
    class Box2d_Util
    {
    public:
        Box2d_Util();
        virtual ~Box2d_Util();

        /**
        @brief Create the world in box2d library.
        @return Return the b2World pointer.
        */
        static b2World* CreateWorld(
            JCS_GameInterface::JCS_VECTOR2F gravity,
            bool sleep = true);

        /**
        @brief Create the Edge shape to the world.
        @param x position
        @param y position
        @param first point
        @param second point
        @param type
        @param density
        */
        static void CreateEdgeShape(
            b2World* world, 
            const float32 xPos,
            const float32 yPos, 
            const b2Vec2& c1, 
            const b2Vec2& c2, 
            const b2BodyType type = b2_dynamicBody,
            const float32 density = 5.0f);

        /**
        @brief Create the box in Box2D lib.
        @param x position
        @param y position
        @param width of box
        @param height of box
        @param type
        @param density
        */
        static void CreateRect(
            b2World* world,
            const float32 xPos,
            const float32 yPos,
            const float32 width,
            const float32 height,
            const b2BodyType type = b2_dynamicBody,
            const float32 density = 5.0f);

        /**
        @brief Create the circle in Box2D lib.
        @param x position
        @param y position
        @param radius
        @param type
        @param density
        */
        static void CreateCircle(
            b2World* world,
            const float32 xPos,
            const float32 yPos,
            const float32 radius,
            const b2BodyType type = b2_dynamicBody,
            const float32 density = 5.0f);

        /** setter **/

        /** getter **/

    };
}

typedef JCS_GameUtil::Box2d_Util Box2d_Util;

#endif // __BOX2D_UTIL_H__
