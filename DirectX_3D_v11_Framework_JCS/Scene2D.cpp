/**
 * $File: Scene2D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Scene2D.h"

#include "Interface2D.h"

namespace JCS_D3DX_v11_Engine
{
    Scene2D::Scene2D()
    {

    }

    Scene2D::~Scene2D()
    {
        for (Interface2D* pInterface : m_interfaces)
            SafeDeleteObject(pInterface);

        GetInterfaces().clear();
    }

    void Scene2D::initialize()
    {

    }

    void Scene2D::update(float32 deltaTime)
    {

    }

    void Scene2D::draw()
    {
        for (Interface2D* pInterface : GetInterfaces())
            pInterface->draw();
    }

    /**
     * Add Interface from this Scene in order to render
     */
    void Scene2D::AddInterface(Interface2D* pInterface)
    {
        if (!pInterface)
        {
            throw GameError(L"Adding Interface that are un-readable memory.");
            return;
        }

        m_interfaces.push_back(pInterface);
    }
    /**
     * Remove Interface from this Scene in order not to render
     */
    void Scene2D::RemoveInterface(Interface2D* pInterface)
    {
        if (!pInterface)
        {
            throw GameError(L"Removing Interface that are un-readable memory.");
            return;
        }

        uint16 i, j;
        for (i = 0; i < GetInterfaces().size(); ++i)
        {
            if (m_interfaces.at(i) == pInterface)
            {
                // 刪除物件
                SafeDeleteObject(m_interfaces.at(i));

                // 移動來補上原本的位置
                for (j = i; j < GetInterfaces().size(); ++j)
                    m_interfaces.at(i) = m_interfaces.at(i + 1);

                // 改變Array大小
                m_interfaces.erase(m_interfaces.begin() + i);
                return;
            }
        }

        throw GameError(L"Object you are trying to remove does not exists in the \"Scene\".");
    }

}

