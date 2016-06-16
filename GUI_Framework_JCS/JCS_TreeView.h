/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_TREEVIEW_H__
#define __JCS_TREEVIEW_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_TreeView
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_TreeView
        : public JCS_WindowHandle
    {
    private:
        bool m_checkBox/* = false*/;

    public:
        JCS_TreeView();
        ~JCS_TreeView();

#ifdef _WIN32
        void Create(const HWND hWnd,
            const LPCWSTR word,
            const int32 x, const int32 y,
            const int32 width, const int32 height,
            const int32 identifier = IDC_NONE);
#endif // _WIN32

        // setter
        const void SetCheckBox(const bool check = false) { this->m_checkBox = check; }

        // getter
        const bool GetCheckBox() const { return this->m_checkBox; }

    private:
#ifdef _WIN32
        void EnableCheckBox();
#endif // _WIN32

    };

}

typedef JCS_GUI::JCS_TreeView JCS_TreeView;

#endif // __JCS_TREEVIEW_H__

