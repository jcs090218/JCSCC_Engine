#include "Interface2D.h"

#include <DirectX_3D_v11_Framework_JCS\GraphicsD3D11.h>

#include "RenderableObject.h"

namespace JCS_D3DX_v11_Engine
{
    Interface2D::Interface2D(GraphicsD3D11* device)
        : m_pSpriteBatch(nullptr)
        , m_position()
        , m_interfaceObjects()
    {
        m_pSpriteBatch = new DirectX::SpriteBatch(device->GetDeviceContext());
    }

    Interface2D::Interface2D(GraphicsD3D11& device)
        : m_pSpriteBatch(nullptr)
        , m_position()
        , m_interfaceObjects()
    {
        m_pSpriteBatch = new DirectX::SpriteBatch(device.GetDeviceContext());
    }

    Interface2D::~Interface2D()
    {
        for (RenderableObject* pRenderableObject : m_interfaceObjects)
            SafeDeleteObject(pRenderableObject);

        GetRenderableObject().clear();
        SafeDeleteObject(m_pSpriteBatch);
    }

    void Interface2D::udpate()
    {

    }

    // Represent one draw call
    void Interface2D::draw()
    {
        GetSpriteBatch()->Begin();

        // Do Render
        for (RenderableObject* pRenderableObject : GetRenderableObject())
            pRenderableObject->draw(GetSpriteBatchRef());


        GetSpriteBatch()->End();
    }
    /**
     * Add Renderable Object into this Interface in order to render
     */
    void Interface2D::AddRenderableObject(RenderableObject* object)
    {
        if (!object)
        {
            throw GameError(L"Adding Renderable Object that are un-readable memory.");
            return;
        }

        // Add into interface
        m_interfaceObjects.push_back(object);
    }
    /**
     * Remove Renderable Object from this Interface in order not to render
     */
    void Interface2D::RemoveRenderableObject(RenderableObject* object)
    {
        if (!object)
        {
            throw GameError(L"Removing Renderable Object that are un-readable memory.");
            return;
        }

        uint16 i, j;
        for (i = 0; i < GetRenderableObject().size(); ++i)
        {
            if (m_interfaceObjects.at(i) == object)
            {
                // 刪除物件
                SafeDeleteObject(m_interfaceObjects.at(i));

                // 移動來補上原本的位置
                for (j = i; j < GetRenderableObject().size(); ++j)
                    m_interfaceObjects.at(i) = m_interfaceObjects.at(i + 1);

                // 改變Array大小
                m_interfaceObjects.erase(m_interfaceObjects.begin() + i);
                return;
            }
        }

        throw GameError(L"Object you are trying to remove does not exists in the \"Interface\".");
    }

}

