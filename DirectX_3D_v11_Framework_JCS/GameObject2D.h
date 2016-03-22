#ifndef _GAMEOBJECT_H__
#define _GAMEOBJECT_H__


#include "RenderableObject.h"
#include "Transform2D.h"

#include <GameInterface_JCS\JCS_Script.h>

namespace JCS_D3DX_v11_Engine
{
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : GameObject2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class GameObject2D
        : public RenderableObject
    {
    protected:
        Transform2D m_transform;
        JCS_Script* m_pScirpt;

    public:
        GameObject2D();
        virtual ~GameObject2D();

        virtual void update(float32 gameTime) = 0;
        virtual void draw(DirectX::SpriteBatch& sprite_batch) override;


        void AttachScript(JCS_Script* script) { this->m_pScirpt = script; }

        // setter
        void SetTransform(const Transform2D& transform) { this->m_transform = transform; }

        // getter
        Transform2D GetTransform() const { return this->m_transform; }
    };

}

#endif // _GAMEOBJECT_H__

