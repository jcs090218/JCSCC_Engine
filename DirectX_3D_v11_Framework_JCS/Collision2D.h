/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D3D11_COLLISION2D_H__
#define __D3D11_COLLISION2D_H__


#include "D3DX_v11_StdAfx.h"

namespace JCS_D3DX_v11_Engine
{
    struct Collision2D
        : public JCS_Collision
    {
        virtual ~Collision2D() { }
    };
}

#endif // __D3D11_COLLISION2D_H__
