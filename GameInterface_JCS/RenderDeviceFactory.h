#ifndef __RENDERDEVICEFACTORY_H__
/**
 * $File: RenderDeviceFactory.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
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

