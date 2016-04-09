/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_LISTBOX_H__
#define __JCS_LISTBOX_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_ListBox
    //
    // Desc : Features.
    //          URL: https://msdn.microsoft.com/en-us/library/windows/desktop/bb775146(v=vs.85).aspx
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_ListBox
        : public JCS_WindowHandle
    {
    public:
        JCS_ListBox();
        ~JCS_ListBox();

#ifdef _WIN32
        void Create(const HWND hWnd,
            const LPCWSTR word,
            const int32 x, const int32 y,
            const int32 width, const int32 height,
            const int32 identifier = IDC_NONE);
#endif // _WIN32

    };

}

typedef JCS_GUI::JCS_ListBox JCS_ListBox;

#endif // __JCS_LISTBOX_H__

