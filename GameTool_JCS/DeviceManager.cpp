/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "DeviceManager.h"


#include <GameInterface_JCS\RenderDeviceFactory.h>

namespace JCS_GameTool
{
    DeviceManager* DeviceManager::s_pDeviceManager = nullptr;

    DeviceManager::DeviceManager()
        : m_pRenderDevice(nullptr)
        , m_pDeviceType(API_Type::NONE)
    {
        
    }

    DeviceManager::~DeviceManager()
    {
        SafeDeleteObject(m_pRenderDevice);
        s_pDeviceManager = nullptr;
    }

    //---------------------------------------------------------------------------------------------------------------------------------------
    // Create Device with different API
    //
    // API include check [RenderDeviceType.h]
    //---------------------------------------------------------------------------------------------------------------------------------------
    void DeviceManager::CreateDevice(API_Type type, HWND hWnd)
    {
        if (m_pRenderDevice != nullptr ||
            m_pDeviceType != API_Type::NONE)
        {
            throw GameError(L"\nFailed to Create Render Device!\n");
            return;
        }

        // Create device
        m_pRenderDevice = RenderDeviceFactory::CreateRenderDevice(type);

        // Iintialize device
        switch (type)
        {
        case API_Type::DIRECT2D:
        {
            if (JCS_D2DEngine::Graphics2D* pDevice = dynamic_cast<JCS_D2DEngine::Graphics2D*>(m_pRenderDevice))
            {
                if (!pDevice->Initialize(hWnd))
                    throw GameError(L"\nFailed to initialize Graphics Device 2D!\n");
            }
        } break;
        case API_Type::DIRECTX3D_9:
        {
            if (JCS_D3DX_v9_Engine::GraphicsD3D9* pDevice = dynamic_cast<JCS_D3DX_v9_Engine::GraphicsD3D9*>(m_pRenderDevice))
            {
                if (!pDevice->Initialize(hWnd, true))
                    throw GameError(L"\nFailed to initialize Graphics3D Version 9!\n");
            }
        } break;
        case API_Type::DIRECTX3D_11:
        {
            if (JCS_D3DX_v11_Engine::GraphicsD3D11* pDevice = dynamic_cast<JCS_D3DX_v11_Engine::GraphicsD3D11*>(m_pRenderDevice))
            {
                if (!pDevice->Initialize(hWnd, true))
                    throw GameError(L"\nFailed to initialize Graphics Device 3D Version 11!\n");
            }
        } break;
        }
    }

}// end namespace "JCS_GameTool"

