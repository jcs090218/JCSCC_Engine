/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Sprite2D.h"


#include <DirectXTK\Inc\WICTextureLoader.h>
#include <DirectX_3D_v11_Framework_JCS\GraphicsD3D11.h>

namespace JCS_D3DX_v11_Engine
{
    Sprite2D::Sprite2D(GraphicsD3D11& device, const wchar_t* filepath, float32 x, float32 y)
        :m_pDevice(device)
        , m_pTexture(nullptr)
        , m_origin(x, y)
    {
        HRESULT hr = DirectX::CreateWICTextureFromFile(
            device.GetDevice(), 
            filepath, 
            nullptr, 
            &m_pTexture);

        if (FAILED(hr))
            throw GameError(L"Failed to load Texture...");
    }

    Sprite2D::~Sprite2D()
    {
        SafeReleaseCOM(m_pTexture);
    }

    void Sprite2D::draw(DirectX::SpriteBatch& sprite_batch)
    {
        sprite_batch.Draw(m_pTexture, m_origin);
    }

}

