/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_WINDOW_H__
#define __JCS_WINDOW_H__


namespace JCS_GameInterface
{
    //-------------------------------------------------------------------------------------------------------
    // JCS_Window
    //
    // Desc : Base class of Window class using any API
    //-------------------------------------------------------------------------------------------------------
    class JCS_GameTool::GameTimer;

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

