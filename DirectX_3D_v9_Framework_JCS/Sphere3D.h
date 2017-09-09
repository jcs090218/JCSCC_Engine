#ifndef __SPHERE3D_H__
/**
 * $File: Sphere3D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __SPHERE3D_H__

#include "Shape3D.h"

namespace JCS_D3DX_v9_Engine
{

	//====================================================================================
	// Name : Sphere3D 
	//
	// Description : 
	//====================================================================================
    class Sphere3D 
        : public Shape3D
    {
    public:
        Sphere3D();
        ~Sphere3D();
    };

}

#endif // __SPHERE3D_H__

