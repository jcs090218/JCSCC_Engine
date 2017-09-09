#ifndef __PHYSICS_2D_H__
/**
 * $File: Physics2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __PHYSICS_2D_H__

#include "D2D_StdAfx.h"

#undef min

namespace JCS_D2DEngine
{
    class Capsule2D;
    class Circle2D;
    class Polygon2D;
    class Rectangle2D;
    class Shape2D;
    class Hexagon2D;

    class RigidBody2D;

    //====================================================================================
    // Class Name : Physics2D
    //
    // Description : Physics wrapper function design here. Usually 
    // using function from "IEMath2D" class.
    //====================================================================================
    class Physics2D
    {
    public:
        Physics2D();
        ~Physics2D();

        /**
            
        */
        static bool PointVSPoint(JCS_GameInterface::JCS_RECT* a, JCS_GameInterface::JCS_RECT* b);
        /**

        */
        static float Distance(JCS_GameInterface::JCS_VECTOR2F* a, JCS_GameInterface::JCS_VECTOR2F* b);
        /**

        */
        static bool CirclevsCircleUnoptimized(Circle2D* a, Circle2D* b);
        /**

        */
        static bool CirclevsCircleOptimized(Circle2D* a, Circle2D* b);
        /**

        */
        static void ResolveCollision(Shape2D* A, Shape2D* B);

    private:
        /**
            Get the relative velocty by passing through
            two velocity. (Vector2)

            @param velocity 1
            @param velocity 2
        */
        static JCS_GameInterface::JCS_VECTOR2F calculateRelativeVelocity(        // 計算 相對速度
            JCS_GameInterface::JCS_VECTOR2F* vel_01, 
            JCS_GameInterface::JCS_VECTOR2F* vel_02);
        /**
            Do Dot Product formula.
        */
        static float DotProduct(JCS_GameInterface::JCS_VECTOR2F vec2, float normal);

        /**
            Calculate the density.
        */
        static float density(float mass, float volume);            // 找密度
        /**
            Calculate the mass.
        */
        static float mass(float density, float volume);            // 找質量
        /**
            Calculate the volume.
        */
        static float volume(float density, float mass);            // 找體積

        /**
            Add two Vector2 together and returns it.

            @param vector2 1
            @param vector2 2
        */
        static JCS_GameInterface::JCS_VECTOR2F VectorAddVector(JCS_GameInterface::JCS_VECTOR2F& vector1, JCS_GameInterface::JCS_VECTOR2F& vector2);
    };
    
}

#endif // __PHYSICS_2D_H__

