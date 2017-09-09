#ifndef __JCS_WINDOWHANDLE_H__
/**
 * $File: JCS_WindowHandle.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_WINDOWHANDLE_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

#ifdef _WIN32
    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_WindowHandle (Abstract class)
    //
    // Description : List of all the components...
    //        URL: https://msdn.microsoft.com/en-us/library/windows/desktop/ms632679(v=vs.85).aspx
    //====================================================================================---------------------------------------------------------------
    class JCS_WindowHandle
    {
    protected:
        HWND m_ownWindow = NULL;    // window handle object.

    public:
        virtual ~JCS_WindowHandle() { }

        /** Return Window handle object. */
        HWND GetOwnWindowHandle() const { return this->m_ownWindow; }
    };
#endif // _WIN32

}

#endif // __JCS_WINDOWHANDLE_H__
