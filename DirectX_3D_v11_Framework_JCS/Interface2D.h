/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D3D11_INTERFACE2D_H__
#define __D3D11_INTERFACE2D_H__

#include "D3DX_v11_StdAfx.h"

#include <DirectXTK\Inc\SpriteBatch.h>
#include <DirectXTK\Inc\SimpleMath.h>

namespace JCS_D3DX_v11_Engine
{
    class GraphicsD3D11;
    class RenderableObject;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Interface
    //
    // Desc : handle each object draw call try as limited as possible
    //        to save performace
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Interface2D
    {
    private:
        DirectX::SpriteBatch* m_pSpriteBatch;
        DirectX::SimpleMath::Vector2 m_position;
        std::vector<RenderableObject*> m_interfaceObjects;

    public:
        explicit Interface2D(GraphicsD3D11* device);
        explicit Interface2D(GraphicsD3D11& device);
        ~Interface2D();

        void AddRenderableObject(RenderableObject* object);
        void RemoveRenderableObject(RenderableObject* object);

        void udpate();
        void draw();

        // setter

        // getter
        DirectX::SpriteBatch* GetSpriteBatch() const { return this->m_pSpriteBatch; }
        DirectX::SpriteBatch& GetSpriteBatchRef() const { return *(this->m_pSpriteBatch); }
        std::vector<RenderableObject*> GetRenderableObject() const { return this->m_interfaceObjects; }
        RenderableObject* GetRenderableObjectPtrAt(const uint32 index) const { return this->m_interfaceObjects.at(index); }
        RenderableObject& GetRenderableObjectRefAt(const uint32 index) const { return *(this->m_interfaceObjects.at(index)); }

    };

}

#endif // __D3D11_INTERFACE2D_H__

