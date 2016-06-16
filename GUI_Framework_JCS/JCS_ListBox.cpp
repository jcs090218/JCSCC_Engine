/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JCS_ListBox.h"


namespace JCS_GUI
{
    JCS_ListBox::JCS_ListBox()
    {

    }

    JCS_ListBox::~JCS_ListBox()
    {

    }

#ifdef _WIN32
    void JCS_ListBox::Create(const HWND hWnd,
        const LPCWSTR word,
        const int32 x, const int32 y,
        const int32 width, const int32 height,
        const int32 identifier /*= IDC_NONE*/)
    {
        HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);

        // Create a push button
        m_ownWindow = CreateWindowEx(NULL,
            L"LISTBOX",
            word,
            WS_TABSTOP | WS_VISIBLE |
            WS_CHILD | BS_DEFPUSHBUTTON,
            x,
            y,
            width,
            height,
            hWnd,
            (HMENU)identifier,
            GetModuleHandle(NULL),
            NULL);

        SendMessage(m_ownWindow,
            WM_SETFONT,
            (WPARAM)hfDefault,
            MAKELPARAM(FALSE, 0));
    }
#endif // _WIN32

}

