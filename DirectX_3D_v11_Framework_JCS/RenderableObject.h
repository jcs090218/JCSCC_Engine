#ifndef __RENDERABLE_H__
#define __RENDERABLE_H__

#include <DirectXTK\Inc\SpriteBatch.h>
#include <GameInterface_JCS\JCS_Component.h>

namespace JCS_D3DX_v11_Engine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // RenderableObject (Interface)
    //
    // Desc : 任何需要"渲染(Render)"的物件必須要"實作(Implement)"
    //        這個"介面(Interface)"
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class RenderableObject
        : public JCS_Component
    {
    public:
        virtual ~RenderableObject() { }

        virtual void draw(DirectX::SpriteBatch& sprite_batch) = 0;
    };

}

#endif // __RENDERABLE_H__

