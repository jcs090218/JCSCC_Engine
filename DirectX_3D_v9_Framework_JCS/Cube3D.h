#ifndef __CUBE3D_H__
/**
 * $File: Cube3D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __CUBE3D_H__

#include "Shape3D.h"

namespace JCS_D3DX_v9_Engine
{

	//====================================================================================
	// Name : Cube3D 
	//
	// Description : 
	//====================================================================================
    class Cube3D 
        : public Shape3D
    {
    public:
        Cube3D();
        ~Cube3D();
    };

}


#endif // __CUBE3D_H__

