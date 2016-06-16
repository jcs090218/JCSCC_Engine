/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __RENDERDEVICE_H__
#define __RENDERDEVICE_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // RenderDevice
    //
    // Desc : Any Render Device should implement this interface.
    //------------------------------------------------------------------------------------
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

