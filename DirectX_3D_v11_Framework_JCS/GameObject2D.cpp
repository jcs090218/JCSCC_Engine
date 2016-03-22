#include "GameObject2D.h"


namespace JCS_D3DX_v11_Engine
{
    GameObject2D::GameObject2D()
        : m_transform()
        , m_pScirpt(nullptr)
    {

    }

    GameObject2D::~GameObject2D()
    {
        SafeDeleteObject(m_pScirpt);
    }

    void GameObject2D::draw(DirectX::SpriteBatch& sprite_batch)
    {

    }

}

