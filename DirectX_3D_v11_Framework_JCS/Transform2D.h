#ifndef __TRANSFORM2D_H__
#define __TRANSFORM2D_H__


#include "D3DX_v11_StdAfx.h"
#include <GameInterface_JCS\JCS_Component.h>

namespace JCS_D3DX_v11_Engine
{
    //-----------------------------------------------------------------------------------------------------------
    // Name : Transform2D
    // 
    // Desc : Record 3 Types of Vector
    //         (1) Position     (位置)
    //         (2) Rotation     (旋轉)
    //         (3) Scale        (大小)
    //-----------------------------------------------------------------------------------------------------------
    struct Transform2D
        : public JCS_Component
    {
        JCS_VECTOR2F m_position;
        JCS_VECTOR2F m_rotation;
        JCS_VECTOR2F m_scale;

        Transform2D()
            : m_position()
            , m_rotation()
            , m_scale(1.0f, 1.0f)
        { }
        virtual ~Transform2D() { }

        // setter
        JCS_VECTOR2F SetPosition(const JCS_VECTOR2F position) { this->m_position = position; }
        JCS_VECTOR2F SetRotation(const JCS_VECTOR2F rotation) { this->m_rotation = rotation; }
        JCS_VECTOR2F SetScale(const JCS_VECTOR2F scale) { this->m_scale = scale; }

        // getter
        JCS_VECTOR2F GetPosition() const { return this->m_position; }
        JCS_VECTOR2F GetRotation() const { return this->m_rotation; }
        JCS_VECTOR2F GetScale() const { return this->m_scale; }

    };

}

#endif // __TRANSFORM2D_H__

