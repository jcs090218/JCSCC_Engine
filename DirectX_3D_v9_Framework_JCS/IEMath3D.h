/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __IEMATH3D_H__
#define __IEMATH3D_H__

#include "D3DX_v9_StdAfx.h"

namespace JCS_D3DX_v9_Engine
{
    class IEMath3D
    {
    public:
        IEMath3D();
        ~IEMath3D();

        static float32 DistanceOfLine(float32 x1 , float32 x2);
        static float32 DistanceBetweenPoint(float32 x, float32 y, float32 z);
        static float32 DistanceBetweenPoint(JCS_GameInterface::JCS_VECTOR3F p1, JCS_GameInterface::JCS_VECTOR3F p2);

    };

}

#endif // __IEMATH3D_H__

