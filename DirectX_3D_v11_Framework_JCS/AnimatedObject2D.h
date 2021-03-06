﻿/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D3D11_ANIMATEDOBJECT_2D_H__
#define __D3D11_ANIMATEDOBJECT_2D_H__


#include "D3DX_v11_StdAfx.h"

#include "RenderableObject.h"
#include "Transform2D.h"

namespace JCS_D3DX_v11_Engine
{
    class Animation2D;

    //====================================================================================---------------------------------------------------------------
    // Name : AnimatedObject2D
    //
    // Description : AnimatedObject is a 2D object holding one "Animation2D".
    //        In order to display and have control with it with "Transform".
    //        (試著做一個class一個責任. 所以"Animation2D"只負責專心做Animation的工作.
    //        "AnimatedObject2D"則會專心在於控制Animation2D物件.)
    //====================================================================================---------------------------------------------------------------
    class AnimatedObject2D
        : public RenderableObject
    {
    private:
        Animation2D* m_pAnimation;
        Transform2D m_transform;

    public:
        AnimatedObject2D(Animation2D* pAnimation = nullptr);
        virtual ~AnimatedObject2D();

        virtual void draw(DirectX::SpriteBatch& sprite_batch) override;

    };

}

#endif // __D3D11_ANIMATEDOBJECT_2D_H__

