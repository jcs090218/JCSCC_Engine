/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Font2D.h"


#include "GraphicsD3D11.h"

namespace JCS_D3DX_v11_Engine
{
    Font2D::Font2D(
        GraphicsD3D11& device, 
        const wchar_t* font, 
        wchar_t* text, 
        float32 x, 
        float32 y)
        : m_pDevice(device)
        , m_pSpriteFont(nullptr)
        , m_origin(x, y)
        , m_text(text)
    {
        // Create Font
        m_pSpriteFont = new DirectX::SpriteFont(device.GetDevice(), font);
    }

    Font2D::~Font2D()
    {
        SafeDeleteObject(m_pSpriteFont);
    }

    void Font2D::draw(DirectX::SpriteBatch& sprite_batch)
    {
        m_pSpriteFont->DrawString(&sprite_batch, m_text, m_origin);
    }

}

