/**
 * $File: RenderDevice.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#ifndef __RENDERDEVICE_H__
#define __RENDERDEVICE_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //====================================================================================
    // RenderDevice
    //
    // Description : Any Render Device should implement this interface.
    //====================================================================================
    class RenderDevice
    {
    public:
        virtual ~RenderDevice() {  }

        virtual void BeginRender() const = 0;
        virtual void EndRender() const = 0;
    };

}

typedef JCS_GameInterface::RenderDevice RenderDevice;

#endif // __RENDERDEVICE_H__

