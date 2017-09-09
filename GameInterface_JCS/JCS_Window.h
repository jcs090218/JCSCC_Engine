/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_WINDOW_H__
#define __JCS_WINDOW_H__


#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    class JCS_GameTool::GameTimer;

    //====================================================================================
    // Class Name: JCS_Window
    // 
    // Description : Base class of Window class using any API
    //====================================================================================
    class JCS_Window
    {
    public:
        virtual ~JCS_Window() { }

        // Show FPS and FrameTime
        virtual void CalculateFrameStats(JCS_GameTool::GameTimer* pTimer) = 0;
    };
}

typedef JCS_GameInterface::JCS_Window JCS_Window;

#endif // __JCS_WINDOW_H__

