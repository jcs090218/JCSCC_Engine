/*******************************************************************
 *                   JCSCC_Framework Version 0.2.7
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   See LICENSE.txt for modification and distribution information
 *               Copyright (c) 2016 by Shen, Jen-Chieh
 ******************************************************************/

#ifndef __D3D11_CIRCLE2D_H__
#define __D3D11_CIRCLE2D_H__

#include "Collision2D.h"

namespace JCS_D3DX_v11_Engine
{
    class Circle2D
        : public Collision2D
    {
    public:
        Circle2D();
        ~Circle2D();

        virtual void Update() override;
        virtual void Draw() override;
    };
}

#endif // __D3D11_CIRCLE2D_H__
