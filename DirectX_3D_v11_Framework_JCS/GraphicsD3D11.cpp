#include "GraphicsD3D11.h"

#include <DirectXColors.h>

namespace JCS_D3DX_v11_Engine
{
    GraphicsD3D11::GraphicsD3D11()
        : m_pDevice(nullptr)
        , m_pImmediateContext(nullptr)
        , m_pSwapChain(nullptr)
        , m_pRenderTargetView(nullptr)
        , m_pDepthStencilView(nullptr)
        , m_vsync(true)                 // enable vsync as default
        , m_driverType()
        , m_featureLevel()
        , m_viewport()
    {

    }

    GraphicsD3D11::~GraphicsD3D11()
    {
        if (m_pImmediateContext) m_pImmediateContext->ClearState();
        SafeReleaseCOM(m_pRenderTargetView);	// Backbuffer device
        SafeReleaseCOM(m_pSwapChain);		    // swapchain device
        SafeReleaseCOM(m_pImmediateContext);	// context device
        SafeReleaseCOM(m_pDevice);		        // d3d11 device (main)
    }

    // Init Direct3D for use
    bool GraphicsD3D11::Initialize(HWND hWnd, bool windowed)
    {
        UINT createDeviceFlags = 0;

        D3D_DRIVER_TYPE driverTypes[] =
        {
            D3D_DRIVER_TYPE_HARDWARE,
            D3D_DRIVER_TYPE_WARP,
            D3D_DRIVER_TYPE_REFERENCE
        };
        UINT numDriverTypes = ARRAYSIZE(driverTypes);		// declare the length of the Array

        D3D_FEATURE_LEVEL featureLevels[] =
        {
            D3D_FEATURE_LEVEL_11_0,
            D3D_FEATURE_LEVEL_10_1,
            D3D_FEATURE_LEVEL_10_0,
            D3D_FEATURE_LEVEL_9_3
        };
        UINT numFeatureLevels = ARRAYSIZE(featureLevels);			// declare the length of the Array

        // Get window's width and height
        RECT rect;
        GetClientRect(hWnd, &rect);

        DXGI_SWAP_CHAIN_DESC scd;
        ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
        scd.BufferCount = 1;            // 0: single buffered, 1:double buffered
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
        scd.BufferDesc.Width = rect.right;
        scd.BufferDesc.Height = rect.bottom;
        scd.BufferDesc.RefreshRate.Numerator = 60;      // frames per second
        scd.BufferDesc.RefreshRate.Denominator = 1;     // second per frame
        scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
        scd.OutputWindow = hWnd;                                // the window to be used
        scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        scd.SampleDesc.Count = 1;                               // how many multisamples
        scd.SampleDesc.Quality = 0;                             // multisample quality level
        scd.Windowed = true;                                    // windowed/full-screen mode
        scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;     // allow full-screen switching


        HRESULT result; // struct of error handle

        for (uint32 i = 0; i < numDriverTypes; ++i)
        {
            result = D3D11CreateDeviceAndSwapChain(
                NULL,
                driverTypes[i],
                NULL,
                createDeviceFlags,
                featureLevels,
                numFeatureLevels,
                D3D11_SDK_VERSION,
                &scd,
                &m_pSwapChain,
                &m_pDevice,
                &m_featureLevel,
                &m_pImmediateContext);

            if (SUCCEEDED(result))
            {
                m_driverType = driverTypes[i];
                break;
            }
        }

        if (FAILED(result))
        {
            throw GameError(L"Failed to create device and swap chain...");
            return false;
        }

        // get the address of the back buffer
        ID3D11Texture2D* pBackBufferTex;
        GetSwapChain()->GetBuffer(NULL, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBackBufferTex));
        GetDevice()->CreateRenderTargetView(pBackBufferTex, nullptr, &m_pRenderTargetView);
        SafeReleaseCOM(pBackBufferTex);

        // Bind render target view
        GetDeviceContext()->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);		// set the render target as the back buffer

        // Set the 
        m_viewport.TopLeftX = 0;
        m_viewport.TopLeftY = 0;
        m_viewport.Width = static_cast<float>(rect.right);
        m_viewport.Height = static_cast<float>(rect.bottom);
        m_viewport.MinDepth = 0.0f;
        m_viewport.MaxDepth = 1.0f;

        GetDeviceContext()->RSSetViewports(1, &m_viewport);		// create viewport

        return true;
    }

    /**
    *  Clear Frame during render
    */
    void GraphicsD3D11::Clear(const FLOAT color[4])
    {
        GetDeviceContext()->ClearRenderTargetView(m_pRenderTargetView, color);		// backbuffer and swapchain
    }

    void GraphicsD3D11::ClearDepth()
    {
        GetDeviceContext()->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    }

    /**
    *	This function will start rendering the frame.
    *  Which is start of the frame
    */
    void GraphicsD3D11::BeginRender() const
    {
        
    }

    /**
    *  This function will tell the program the frame end!
    */
    void GraphicsD3D11::EndRender() const
    {

    }

    /**
    *	This function will display the frame.
    */
    void GraphicsD3D11::RenderPresent()
    {
        // switch the back buffer and the front buffer
        GetSwapChain()->Present(GetVsync(), 0);
    }

}

