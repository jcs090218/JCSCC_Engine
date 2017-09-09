#ifndef __D3D11_CAMERA2D_H__
/**
 * $File: Camera2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D3D11_CAMERA2D_H__


#include "Transform2D.h"

namespace JCS_D3DX_v11_Engine
{
	class Transform2D;

	//====================================================================================
	// Name : Camera2D 
	//
	// Description : 
	//====================================================================================
	class Camera2D
	{
	private:
		bool m_smoothEffect;
		Transform2D m_transform;
		Transform2D* m_pTargetTranform;
		float32 m_friction;

	public:
		Camera2D();
		~Camera2D();

		void Update(float32 deltaTime);

		// Movement Effect
		void SmoothEffect(float32 deltaTime);

	};
}

#endif // __D3D11_CAMERA2D_H__
