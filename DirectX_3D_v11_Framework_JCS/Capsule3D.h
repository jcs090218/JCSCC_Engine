/*******************************************************************
 *                   JCSCC_Framework Version 0.2.7
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   See LICENSE.txt for modification and distribution information
 *              Copyright (c) 2016 by Shen, Jen-Chieh
 ******************************************************************/

#ifndef __D3D11_CAPSULE3D_H__
#define __D3D11_CAPSULE3D_H__

#include "Collision3D.h"

namespace JCS_D3DX_v11_Engine
{
    class Capsule3D
        : public Collision3D
    {
    public:
        Capsule3D();
        ~Capsule3D();

        virtual void Update() override;
        virtual void Draw() override;

    };
}

#endif // __D3D11_CAPSULE3D_H__
