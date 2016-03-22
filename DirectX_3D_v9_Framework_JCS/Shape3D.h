#ifndef __SHAPE3D_H__
#define __SHAPE3D_H__

#include "GameObject3D.h"


namespace JCS_D3DX_v9_Engine
{
	class Shape3D 
        : public GameObject3D
	{
	public:
		Shape3D();
		Shape3D(float32 x, float32 y);
		~Shape3D();
	};

}

#endif // __SHAPE3D_H__

