/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D3D11_CAPSULE2D_H__
#define __D3D11_CAPSULE2D_H__


#include "Collision2D.h"

namespace JCS_D3DX_v11_Engine
{

    class Capsule2D
        : public Collision2D
    {
    public:
        Capsule2D();
        ~Capsule2D();

        virtual void Update() override;
        virtual void Draw() override;

    };
}

#endif // __D3D11_CAPSULE2D_H__
