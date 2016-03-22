#ifndef __SPRITE2D_H__
#define __SPRITE2D_H__

#include "D3DX_v11_StdAfx.h"
#include <DirectXTK\Inc\SimpleMath.h>

#include "RenderableObject.h"

namespace JCS_D3DX_v11_Engine
{
    class GraphicsD3D11;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Sprite2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Sprite2D
        : public RenderableObject
    {
    private:
        GraphicsD3D11& m_pDevice;

        ID3D11ShaderResourceView* m_pTexture;
        DirectX::SimpleMath::Vector2 m_origin;  // sprite position

    public:
        Sprite2D(GraphicsD3D11& device,
            const wchar_t* filepath, 
            float32 x = 0.0f, 
            float32 y = 0.0f);
        virtual ~Sprite2D();

        virtual void draw(DirectX::SpriteBatch& sprite_batch) override;

        // setter
        void SetOrigin(const DirectX::SimpleMath::Vector2& origin) { this->m_origin = origin; }
        void SetOrigin(const float32 x, const float32 y) { this->SetOrigin(DirectX::SimpleMath::Vector2(x, y)); }
        void SetOrigin(const JCS_VECTOR2F& vec) { this->SetOrigin(DirectX::SimpleMath::Vector2(vec.x, vec.y)); }

        // getter
        DirectX::SimpleMath::Vector2 GetOrigin() const { return this->m_origin; }

    };

}

#endif // __SPRITE_H__

