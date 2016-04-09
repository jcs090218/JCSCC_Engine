/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GRAPHICSD3D11_H__
#define __GRAPHICSD3D11_H__

#include "D3DX_v11_StdAfx.h"

#include <GameInterface_JCS\RenderDevice.h>

namespace JCS_D3DX_v11_Engine
{
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : GraphicsD3D11
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class GraphicsD3D11
        : public RenderDevice
    {
    protected:
        ID3D11Device* m_pDevice;                     // the pointer to our Direct3D device interface
        ID3D11DeviceContext* m_pImmediateContext;

        IDXGISwapChain* m_pSwapChain;             // the pointer to the swap chain interface
        ID3D11RenderTargetView* m_pRenderTargetView;    // the pointer to our back buffer
        ID3D11DepthStencilView* m_pDepthStencilView;		// the pointer to z-buffer

        D3D_DRIVER_TYPE	m_driverType;
        D3D_FEATURE_LEVEL m_featureLevel;
        D3D11_VIEWPORT m_viewport;

        bool m_vsync;

    public:
        GraphicsD3D11();
        virtual ~GraphicsD3D11();

        // Direct3D functions
        bool Initialize(HWND hWnd, bool windowed);

        virtual void BeginRender() const override;
        virtual void EndRender() const override;

        void Clear(const FLOAT color[4]);		// this will help us clear the frame
        void ClearDepth();
        void RenderPresent();

        // setter
        void SetVsync(const bool vsync) { this->m_vsync = vsync; }

        // getter
        bool GetVsync() const { return this->m_vsync; }
        ID3D11Device* GetDevice() const { return this->m_pDevice; }
        ID3D11Device& GetDeviceRef() const { return *(this->m_pDevice); }
        ID3D11DeviceContext* GetDeviceContext() const { return this->m_pImmediateContext; }
        ID3D11DeviceContext& GetDeviceContextRef() const { return *(this->m_pImmediateContext); }
        IDXGISwapChain* GetSwapChain() const { return this->m_pSwapChain; }
        IDXGISwapChain& GetSwapChainRef() const { return *(this->m_pSwapChain); }
    };
}

typedef JCS_D3DX_v11_Engine::GraphicsD3D11 GraphicsD3D11;

#endif // __GRAPHICSD3D11_H__

