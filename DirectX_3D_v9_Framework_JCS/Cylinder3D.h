#ifndef __CYLINDER3D_H__
/**
 * $File: Cylinder3D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __CYLINDER3D_H__

#include "Shape3D.h"


namespace JCS_D3DX_v9_Engine
{

	//====================================================================================
	// Name : Cylinder3D 
	//
	// Description : 
	//====================================================================================
    class Cylinder3D 
        : public Shape3D
    {
    public:
        Cylinder3D();
        ~Cylinder3D();
    };
}

#endif // __CYLINDER3D_H__
