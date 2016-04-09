/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "AnimatedObject2D.h"

#include "Animation2D.h"

namespace JCS_D3DX_v11_Engine
{
    AnimatedObject2D::AnimatedObject2D(Animation2D* pAnimation)
        : m_pAnimation(pAnimation)
        , m_transform()
    {

    }

    AnimatedObject2D::~AnimatedObject2D()
    {
        SafeDeleteObject(m_pAnimation);
    }

    void AnimatedObject2D::draw(DirectX::SpriteBatch& sprite_batch)
    {
        m_pAnimation->DrawAnimation(sprite_batch);
    }

}

