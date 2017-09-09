/**
 * $File: JCS_TreeView.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "JCS_TreeView.h"


namespace JCS_GUI
{
    JCS_TreeView::JCS_TreeView()
        : m_checkBox(false)
    {

    }

    JCS_TreeView::~JCS_TreeView()
    {

    }

#ifdef _WIN32
    void JCS_TreeView::Create(const HWND hWnd, 
        const LPCWSTR word, 
        const int32 x, const int32 y,
        const int32 width, const int32 height,
        const int32 identifier /*= IDC_NONE*/)
    {
        HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);

        m_ownWindow = CreateWindowEx(0,
            WC_TREEVIEW,
            word,
            WS_VISIBLE | WS_CHILD | WS_BORDER | TVS_HASLINES,
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

    void JCS_TreeView::EnableCheckBox()
    {
        // Check if use check box for the node.
        // Once it open then all node will have check box infront.
        if (GetCheckBox())
        {
            DWORD dwStyle = GetWindowLong(GetOwnWindowHandle(), GWL_STYLE);
            dwStyle |= TVS_CHECKBOXES;
            SetWindowLongPtr(GetOwnWindowHandle(), GWL_STYLE, dwStyle);
        }
    }

#endif // _WIN32

}

