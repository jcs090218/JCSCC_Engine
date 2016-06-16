/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "GraphicsD3D9.h"


namespace JCS_D3DX_v9_Engine
{
    GraphicsD3D9::GraphicsD3D9()
        : m_direct3d()
        , m_d3ddev()
    {
        
    }

    // Destructor-> Release() and COM
    GraphicsD3D9::~GraphicsD3D9()
    {
        SafeReleaseCOM(m_d3ddev);        // d3d9 device (main)
        SafeReleaseCOM(m_direct3d);        // 
    }

    // Init Direct3D for use
    bool GraphicsD3D9::Initialize(HWND hWnd, bool windowed)
    {
        // Create the Direct3D pointer
        m_direct3d = Direct3DCreate9(D3D_SDK_VERSION);

        D3DPRESENT_PARAMETERS d3dpp;

        RECT rect;
        GetClientRect(hWnd, &rect);

        ZeroMemory(&d3dpp, sizeof(d3dpp));
        d3dpp.Windowed = windowed;
        d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
        d3dpp.hDeviceWindow = hWnd;
        d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
        d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;        // set vsync
        d3dpp.BackBufferWidth = rect.right;
        d3dpp.BackBufferHeight = rect.bottom;
        d3dpp.EnableAutoDepthStencil = TRUE;            // automatically run the z-buffer for us
        d3dpp.AutoDepthStencilFormat = D3DFMT_D16;        // 16-bit pixel format for the z-buffer

        // create a device class using this information and the info from them d3dpp struct
        if (!SUCCEEDED(m_direct3d->CreateDevice(D3DADAPTER_DEFAULT,
            D3DDEVTYPE_HAL,
            hWnd,
            D3DCREATE_SOFTWARE_VERTEXPROCESSING,
            &d3dpp,
            &m_d3ddev)))
        {
            return false;
        }

        // addition Render States
        GetDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);    // turn off the 3D lighting
        GetDevice()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);    // both sides of the triangles
        GetDevice()->SetRenderState(D3DRS_ZENABLE, TRUE);        // turn on the z-buffer

        return true;
    }

    /**
     *  Clear Frame during render
     */
    void GraphicsD3D9::Clear(D3DXCOLOR& color)
    {
        GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);                            // screen renderer
    }

    void GraphicsD3D9::ClearDepth()
    {
        GetDevice()->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);        // z-buffer
    }

    /**
     *    This function will start rendering the frame.
     *  Which is start of the frame
     */
    void GraphicsD3D9::BeginRender() const
    {
        GetDevice()->BeginScene();
    }

    /**
     *  This function will tell the program the frame end!
     */
    void GraphicsD3D9::EndRender() const
    {
        GetDevice()->EndScene();
    }

    /**
     *    This function will display the frame.
     */
    void GraphicsD3D9::RenderPresent()
    {
        //Present our scene to the window.
        GetDevice()->Present(NULL, NULL, NULL, NULL);
    }

}

