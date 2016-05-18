/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "GameObject2D.h"


namespace JCS_D3DX_v11_Engine
{

    GameObject2D::GameObject2D()
        : m_transform()
        , m_pScript(nullptr)
    {

    }

    GameObject2D::~GameObject2D()
    {
        SafeDeleteObject(m_pScript);
    }

    void GameObject2D::update(float32 deltaTime)
    {
        // run the script
        if (m_pScript)
        {
            // do the c++'s script before we get into the 
            // other language's script
            m_pScript->update(deltaTime);
            m_pScript->Update();
        }
    }

    void GameObject2D::draw(DirectX::SpriteBatch& sprite_batch)
    {

    }

}

