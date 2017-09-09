#ifndef __IEMATH2D_H__
/**
 * $File: IEMath2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __IEMATH2D_H__

#include "D2D_StdAfx.h"

namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : IEMath2D
    //
    // Description : Useful math function implement here.
    //====================================================================================
    class IEMath2D
    {
    public:
        IEMath2D();
        ~IEMath2D();

        /**
            Return the distance of unit vector.

            @param vector value 1
            @param vector value 2
        */
        static float32 DistanceOfUnitVector(float32 x1, float32 x2);
        /**
            Return the distance between two point.

            @param point 1
            @param point 2
        */
        static float32 DistanceBetweenPoint(float32 p1, float32 p2);

        /**
            Return the distance between two point.

            @param point 1
            @param point 2
        */
        static float32 DistanceBetweenPoint(
            JCS_GameInterface::JCS_VECTOR2F& p1, JCS_GameInterface::JCS_VECTOR2F& p2);

        /**
            Return the calcuate movement be rotating.

            @param point
            @param cosine angle
            @param sine angle
            @param origin point
        */
        static JCS_GameInterface::JCS_VECTOR2F RotatePoint(
            JCS_GameInterface::JCS_VECTOR2F& point, float32 cosΘ, float32 sinΘ,
            JCS_GameInterface::JCS_VECTOR2F& origin);

        /**
            Do dot product.

            @param
            @param
        */
        static float32 DotProduct(
            const JCS_GameInterface::JCS_VECTOR2F& vectorA, const JCS_GameInterface::JCS_VECTOR2F& vectorB);
        /**
            Do cross product.

            @param
            @param
        */
        static float32 CrossProduct(
            const JCS_GameInterface::JCS_VECTOR2F& vectorA, const JCS_GameInterface::JCS_VECTOR2F& vectorB);
        /**
            Do cross product.

            @param
            @param
        */
        static JCS_GameInterface::JCS_VECTOR2F CrossProduct(
            float32 a, const JCS_GameInterface::JCS_VECTOR2F& vector);

    };

    /**
        Return the distance of unit vector.

        @param vector value 1
        @param vector value 2
    */
    inline float32 DistanceOfUnitVector(float32 x1, float32 x2)
    {
        return IEMath2D::DistanceOfUnitVector(x1, x2);
    }
    /**
        Return the distance between two point.

        @param point 1
        @param point 2
    */
    inline float32 DistanceBetweenPoint(float32 p1, float32 p2)
    {
        return IEMath2D::DistanceBetweenPoint(p1, p2);
    }

    /**
        Return the distance between two point.

        @param point 1
        @param point 2
    */
    inline float32 DistanceBetweenPoint(JCS_GameInterface::JCS_VECTOR2F& p1, JCS_GameInterface::JCS_VECTOR2F& p2)
    {
        return IEMath2D::DistanceBetweenPoint(p1, p2);
    }

    /**
        Return the calcuate movement be rotating.

        @param point
        @param cosine angle
        @param sine angle
        @param origin point
    */
    inline JCS_GameInterface::JCS_VECTOR2F RotatePoint(
        JCS_GameInterface::JCS_VECTOR2F& point, float32 cosΘ, float32 sinΘ,
        JCS_GameInterface::JCS_VECTOR2F& origin)
    {
        return IEMath2D::RotatePoint(point, cosΘ, sinΘ, origin);
    }

}

#endif // __IEMATH2D_H__

