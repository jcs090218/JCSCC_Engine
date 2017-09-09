#ifndef __SHAPE3D_H__
/**
 * $File: Shape3D.h $
 * $Date: 2016-11-09 22:44:14 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SHAPE3D_H__

#include "GameObject3D.h"


namespace JCS_D3DX_v9_Engine
{

	//====================================================================================
	// Name : Shape3D 
	//
	// Description : 
	//====================================================================================
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
