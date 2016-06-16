#ifndef __IEMATH2D_H__
#define __IEMATH2D_H__

#include "D2D_StdAfx.h"

namespace JCS_D2DEngine
{
    class IEMath2D
    {
    public:
        IEMath2D();
        ~IEMath2D();

        static float32 DistanceOfUnitVector(float32 x1, float32 x2);
        static float32 DistanceBetweenPoint(float32 p1, float32 p2);
        static float32 DistanceBetweenPoint(
            JCS_GameInterface::JCS_VECTOR2F& p1, JCS_GameInterface::JCS_VECTOR2F& p2);

        static JCS_GameInterface::JCS_VECTOR2F RotatePoint(
            JCS_GameInterface::JCS_VECTOR2F& point, float32 cosΘ, float32 sinΘ,
            JCS_GameInterface::JCS_VECTOR2F& origin);

        static float32 DotProduct(
            const JCS_GameInterface::JCS_VECTOR2F& vectorA, const JCS_GameInterface::JCS_VECTOR2F& vectorB);
        static float32 CrossProduct(
            const JCS_GameInterface::JCS_VECTOR2F& vectorA, const JCS_GameInterface::JCS_VECTOR2F& vectorB);
        static JCS_GameInterface::JCS_VECTOR2F CrossProduct(
            float32 a, const JCS_GameInterface::JCS_VECTOR2F& vector);

    };

    inline float32 DistanceOfUnitVector(float32 x1, float32 x2)
    {
        return IEMath2D::DistanceOfUnitVector(x1, x2);
    }

    inline float32 DistanceBetweenPoint(float32 p1, float32 p2)
    {
        return IEMath2D::DistanceBetweenPoint(p1, p2);
    }

    inline float32 DistanceBetweenPoint(JCS_GameInterface::JCS_VECTOR2F& p1, JCS_GameInterface::JCS_VECTOR2F& p2)
    {
        return IEMath2D::DistanceBetweenPoint(p1, p2);
    }

    inline JCS_GameInterface::JCS_VECTOR2F RotatePoint(
        JCS_GameInterface::JCS_VECTOR2F& point, float32 cosΘ, float32 sinΘ,
        JCS_GameInterface::JCS_VECTOR2F& origin)
    {
        return IEMath2D::RotatePoint(point, cosΘ, sinΘ, origin);
    }

}

#endif // __IEMATH2D_H__

