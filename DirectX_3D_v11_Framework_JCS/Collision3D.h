#ifndef __D3D11_COLLISION3D_H__
/**
 * $File: Collision3D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D3D11_COLLISION3D_H__


#include "D3DX_v11_StdAfx.h"

namespace JCS_D3DX_v11_Engine
{
	//====================================================================================
	// Name : Collision3D 
	//
	// Description : 
	//====================================================================================
    struct Collision3D
        : public JCS_Collision
    {
        virtual ~Collision3D() { }
    };
}

#endif // __D3D11_COLLISION3D_H__
