#ifndef __CAPSULE3D_H__
/**
 * $File: Capsule3D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __CAPSULE3D_H__

#include "Shape3D.h"


namespace JCS_D3DX_v9_Engine
{

	//====================================================================================
	// Name : Capsule3D 
	//
	// Description : 
	//====================================================================================
    class Capsule3D
        : public Shape3D
    {
    public:
        Capsule3D();
        ~Capsule3D();
    };

}

#endif // __CAPSULE3D_H__

