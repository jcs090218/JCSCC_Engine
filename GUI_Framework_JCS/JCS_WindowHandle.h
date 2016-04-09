/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_WINDOWHANDLE_H__
#define __JCS_WINDOWHANDLE_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

#ifdef _WIN32
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_WindowHandle (Abstract class)
    //
    // Desc : List of all the components...
    //        URL: https://msdn.microsoft.com/en-us/library/windows/desktop/ms632679(v=vs.85).aspx
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_WindowHandle
    {
    protected:
        HWND m_ownWindow = NULL;

    public:
        virtual ~JCS_WindowHandle() { }

        HWND GetOwnWindowHandle() const { return this->m_ownWindow; }
    };
#endif // _WIN32

}

#endif // __JCS_WINDOWHANDLE_H__

