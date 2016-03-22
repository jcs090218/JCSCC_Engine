#include "RenderDeviceFactory.h"

// All the render devices currently appear
#include <Direct_2D_Framework_JCS\Graphics2D.h>
#include <DirectX_3D_v9_Framework_JCS\GraphicsD3D9.h>
#include <DirectX_3D_v11_Framework_JCS\GraphicsD3D11.h>

// Create the device we want to use (API)
RenderDevice* RenderDeviceFactory::CreateRenderDevice(API_Type type)
{
    switch (type)
    {
    case API_Type::DIRECT2D: { return new JCS_D2DEngine::Graphics2D(); }
    case API_Type::DIRECTX3D_9: { return new JCS_D3DX_v9_Engine::GraphicsD3D9(); }
    case API_Type::DIRECTX3D_11: { return new JCS_D3DX_v11_Engine::GraphicsD3D11(); }
    case API_Type::OPENGL: { return nullptr; }
    case API_Type::NONE: { return nullptr; }
    default: { return nullptr; }
    }
}

