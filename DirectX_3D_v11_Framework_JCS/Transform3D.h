/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D3D11_TRANSFORM3D_H__
#define __D3D11_TRANSFORM3D_H__

#include "D3DX_v11_StdAfx.h"
#include <GameInterface_JCS\JCS_Transform.h>

namespace JCS_D3DX_v11_Engine
{

    //-----------------------------------------------------------------------------------------------------------
    // Name : Transform2D
    // 
    // Desc : "Transform3D" is also the node itself.
    //        Record 3 Types of Vector
    //         (1) Position     (位置)
    //         (2) Rotation     (旋轉)
    //         (3) Scale        (大小)
    //-----------------------------------------------------------------------------------------------------------
    class Transform3D
        : public JCS_Transform
    {
    private:
        Transform3D* m_pParent;
        std::vector<Transform3D*> m_childrens;

    public:
        JCS_VECTOR3F position;
        JCS_VECTOR3F rotation;
        JCS_VECTOR3F scale;

        explicit Transform3D()
            : position()
            , rotation()
            , scale(1.0f, 1.0f, 1.0f)
            , m_pParent(nullptr)
            , m_childrens()
        { }

        ~Transform3D() { }

        Transform3D* GetParent() const { return this->m_pParent; }
        std::vector<Transform3D*> GetChildrens() const { return this->m_childrens; }
        Transform3D& GetChildrensRef(const int32 index) const { return *(this->m_childrens.at(index)); }
        Transform3D* GetChildrensPtr(const int32 index) const { return this->m_childrens.at(index); }

    };
}

#endif // __D3D11_TRANSFORM3D_H__
