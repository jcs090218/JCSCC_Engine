/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D3D11_FONT_2D_H__
#define __D3D11_FONT_2D_H__


#include <DirectXTK\Inc\SimpleMath.h>
#include <DirectXTK\Inc\SpriteFont.h>

#include "D3DX_v11_StdAfx.h"
#include "RenderableObject.h"

namespace JCS_D3DX_v11_Engine
{
    class GraphicsD3D11;

    class Font2D
        : public RenderableObject
    {
    private:
        DirectX::SpriteFont* m_pSpriteFont;
        GraphicsD3D11& m_pDevice;
        DirectX::SimpleMath::Vector2 m_origin;
        wchar_t* m_text;

    public:
        explicit Font2D(GraphicsD3D11& device,
            const wchar_t* font,
            wchar_t* text = L"Default Text",
            float32 x = 0.0f, 
            float32 y = 0.0f);
        ~Font2D();

        virtual void draw(DirectX::SpriteBatch& sprite_batch) override;

        // setter
        void SetOrigin(DirectX::SimpleMath::Vector2 origin) { this->m_origin = origin; }

        // getter
        DirectX::SimpleMath::Vector2 GetOrigin() const { return this->m_origin; }

    };

}

#endif // __D3D11_FONT_2D_H__

