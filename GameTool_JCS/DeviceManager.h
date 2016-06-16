/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __DEVICEMANAGER_H__
#define __DEVICEMANAGER_H__

#include "GameTool_StdAfx.h"

// Render Devices
#include <Direct_2D_Framework_JCS\Graphics2D.h>
#include <DirectX_3D_v9_Framework_JCS\GraphicsD3D9.h>
#include <DirectX_3D_v11_Framework_JCS\GraphicsD3D11.h>

namespace JCS_GameTool
{
    class JCS_GameInterface::RenderDevice;

    //------------------------------------------------------------------------------------
    // Name : DeviceManager 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class DeviceManager
    {
    private:
        static DeviceManager* s_pDeviceManager;

        API_Type m_pDeviceType;
        RenderDevice* m_pRenderDevice;

        DeviceManager();

    public:
        virtual ~DeviceManager();

        static DeviceManager* getInstance()
        {
            if (!s_pDeviceManager)
                s_pDeviceManager = new DeviceManager();
            return s_pDeviceManager;
        }

        void CreateDevice(API_Type type, HWND hWnd);

        // setter

        // getter
        RenderDevice* GetRednerDeviceAsPtr() const { return this->m_pRenderDevice; }
        RenderDevice& GetRednerDeviceAsRef() const { return *(this->m_pRenderDevice); }

        // Direct2D
        JCS_D2DEngine::Graphics2D* DeviceManager::GetDirect2DDeviceAsPtr() const { return dynamic_cast<JCS_D2DEngine::Graphics2D*>(m_pRenderDevice); }
        JCS_D2DEngine::Graphics2D& DeviceManager::GetDirect2DDeviceAsRef() const { return *(dynamic_cast<JCS_D2DEngine::Graphics2D*>(m_pRenderDevice)); }

        // DirectX3D Version 9
        JCS_D3DX_v9_Engine::GraphicsD3D9* DeviceManager::GetDriectX3D_v9_DeviceAsPtr() const { return dynamic_cast<JCS_D3DX_v9_Engine::GraphicsD3D9*>(m_pRenderDevice); }
        JCS_D3DX_v9_Engine::GraphicsD3D9& DeviceManager::GetDriectX3D_v9_DeviceAsRef() const { return *(dynamic_cast<JCS_D3DX_v9_Engine::GraphicsD3D9*>(m_pRenderDevice)); }

        // DirectX3D Version 11
        JCS_D3DX_v11_Engine::GraphicsD3D11* DeviceManager::GetDriectX3D_v11_DeviceAsPtr() const { return dynamic_cast<JCS_D3DX_v11_Engine::GraphicsD3D11*>(m_pRenderDevice); }
        JCS_D3DX_v11_Engine::GraphicsD3D11& DeviceManager::GetDriectX3D_v11_DeviceAsRef() const { return *(dynamic_cast<JCS_D3DX_v11_Engine::GraphicsD3D11*>(m_pRenderDevice)); }

    private:
        void SetRenderDeviceType(const API_Type type) { this->m_pDeviceType = type; }
    };

}

typedef JCS_GameTool::DeviceManager DeviceManager;

#endif // __DEVICEMANAGER_H__

