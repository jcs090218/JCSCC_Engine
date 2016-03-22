#ifndef __RENDERDEVICEFACTORY_H__
#define __RENDERDEVICEFACTORY_H__

#include "API_Type.h"


namespace JCS_GameInterface
{
    class RenderDevice;

    class RenderDeviceFactory
    {
    public:
        static RenderDevice* CreateRenderDevice(API_Type type);
    };
}

typedef JCS_GameInterface::RenderDeviceFactory RenderDeviceFactory;

#endif // __RENDERDEVICEFACTORY_H__

