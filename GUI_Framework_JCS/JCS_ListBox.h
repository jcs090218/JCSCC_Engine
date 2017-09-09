#ifndef __JCS_LISTBOX_H__
/**
 * $File: JCS_ListBox.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_LISTBOX_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_ListBox
    //
    // Description : Features.
    //          URL: https://msdn.microsoft.com/en-us/library/windows/desktop/bb775146(v=vs.85).aspx
    //====================================================================================---------------------------------------------------------------
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

