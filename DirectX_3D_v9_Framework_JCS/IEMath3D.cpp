/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "IEMath3D.h"


namespace JCS_D3DX_v9_Engine
{
	IEMath3D::IEMath3D()
	{
	}


	IEMath3D::~IEMath3D()
	{
	}

	/**
	 * 找出 x , y 或 z 的距離
	 */
	float32 IEMath3D::DistanceOfLine(float32 x1, float32 x2)
	{
		float32 distance = x2 - x1;
		if (distance < 0) distance = -distance;
		return distance;
	}
	/**
	 * 代入距離
	 *
	 * d^2 = a^2 + b^2 + c^2
	 */
	float32 IEMath3D::DistanceBetweenPoint(float32 x, float32 y, float32 z)
	{
        return sqrt(JCS_GameInterface::Sqr(x) + JCS_GameInterface::Sqr(y) + JCS_GameInterface::Sqr(z));
	}

	/**
	 * 代入三點
	 *
	 * d^2 = (x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2
	 */
    float32 IEMath3D::DistanceBetweenPoint(JCS_GameInterface::JCS_VECTOR3F p1, JCS_GameInterface::JCS_VECTOR3F p2)
	{
        return sqrt(JCS_GameInterface::Sqr(p2.x - p1.x) + JCS_GameInterface::Sqr(p2.y - p1.y) + JCS_GameInterface::Sqr(p2.z - p1.z));
	}

}

