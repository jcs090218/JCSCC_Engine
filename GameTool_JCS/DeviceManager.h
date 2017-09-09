#ifndef __DEVICEMANAGER_H__
/**
 * $File: DeviceManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __DEVICEMANAGER_H__

#include "GameTool_StdAfx.h"

// Render Devices
#include <Direct_2D_Framework_JCS\Graphics2D.h>
#include <DirectX_3D_v9_Framework_JCS\GraphicsD3D9.h>
#include <DirectX_3D_v11_Framework_JCS\GraphicsD3D11.h>

namespace JCS_GameTool
{
    class JCS_GameInterface::RenderDevice;

    //====================================================================================
    // Class Name : DeviceManager 
    //
    // Description : Manager manages all the device including
    //              render device
    //====================================================================================
    class DeviceManager
		: public JCSSTL::JCSSTL_Singleton<DeviceManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<DeviceManager>;

        API_Type m_pDeviceType;
        RenderDevice* m_pRenderDevice;

    public:
        virtual ~DeviceManager();

        void CreateDevice(API_Type type, HWND hWnd);

        /** setter **/

        /** getter **/

        /** Base Class of the render device by pointer. */
        RenderDevice* GetRenderDeviceAsPtr() const { return this->m_pRenderDevice; }
        /** Base Class of the render device by reference. */
        RenderDevice& GetRenderDeviceAsRef() const { return *(this->m_pRenderDevice); }

        // Direct2D

        /** Direct 2D of the render device by pointer. */
        JCS_D2DEngine::Graphics2D* DeviceManager::GetDirect2DDeviceAsPtr() const { return dynamic_cast<JCS_D2DEngine::Graphics2D*>(m_pRenderDevice); }
        /** Direct 2D of the render device by reference. */
        JCS_D2DEngine::Graphics2D& DeviceManager::GetDirect2DDeviceAsRef() const { return *(dynamic_cast<JCS_D2DEngine::Graphics2D*>(m_pRenderDevice)); }

        // DirectX3D Version 9

        /** DirectX 9 of the render device by pointer. */
        JCS_D3DX_v9_Engine::GraphicsD3D9* DeviceManager::GetDriectX3D_v9_DeviceAsPtr() const { return dynamic_cast<JCS_D3DX_v9_Engine::GraphicsD3D9*>(m_pRenderDevice); }
        /** DirectX 9 of the render device by reference. */
        JCS_D3DX_v9_Engine::GraphicsD3D9& DeviceManager::GetDriectX3D_v9_DeviceAsRef() const { return *(dynamic_cast<JCS_D3DX_v9_Engine::GraphicsD3D9*>(m_pRenderDevice)); }

        // DirectX3D Version 11

        /** DirectX 11 of the render device by pointer. */
        JCS_D3DX_v11_Engine::GraphicsD3D11* DeviceManager::GetDriectX3D_v11_DeviceAsPtr() const { return dynamic_cast<JCS_D3DX_v11_Engine::GraphicsD3D11*>(m_pRenderDevice); }
        /** DirectX 11 of the render device by reference. */
        JCS_D3DX_v11_Engine::GraphicsD3D11& DeviceManager::GetDriectX3D_v11_DeviceAsRef() const { return *(dynamic_cast<JCS_D3DX_v11_Engine::GraphicsD3D11*>(m_pRenderDevice)); }

    private:
		// Constructor
		DeviceManager();
		DeviceManager(const DeviceManager& right) = delete;

        /** Set the render device type in order to get the correct render device */
        void SetRenderDeviceType(const API_Type type) { this->m_pDeviceType = type; }
		
    };

}

typedef JCS_GameTool::DeviceManager DeviceManager;

#endif // __DEVICEMANAGER_H__

