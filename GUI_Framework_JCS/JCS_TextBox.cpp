/**
 * $File: JCS_TextBox.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "JCS_TextBox.h"


namespace JCS_GUI
{

    JCS_TextBox::JCS_TextBox()
    {

    }

    JCS_TextBox::~JCS_TextBox()
    {

    }

#ifdef _WIN32
    void JCS_TextBox::Create(const HWND hWnd, 
                             const LPCWSTR word, 
                             const int32 x, const int32 y, 
                             const int32 width, const int32 height, 
                             const int32 identifier /*= IDC_NONE*/)
    {
        HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);

        m_ownWindow = CreateWindowEx(WS_EX_CLIENTEDGE,
            L"EDIT",
            word,
            WS_CHILD | WS_VISIBLE |
            ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
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

