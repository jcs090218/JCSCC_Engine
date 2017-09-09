#ifndef __JCS_MENUBAR_H__
/**
 * $File: JCS_MenuBar.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_MENUBAR_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_MenuBar
    //
    // Description : JCSCC Menu Bar GUI.
    //====================================================================================---------------------------------------------------------------
    class JCS_MenuBar
        : public JCS_WindowHandle
    {
    private:
        HMENU m_menubar;    // menu object

    public:
        JCS_MenuBar();
        ~JCS_MenuBar();

#ifdef _WIN32
        /**
            Add the attribute in this menu attribute.

            @param menu
            @param word
        */
        void AddMenuAttribute(const int32 menu, const LPCWSTR word);
        /**
            Add the function attribute in this menu attribute.

            @param word
            @param identifier
        */
        void AddFunctionAttribute(const LPCWSTR word, const int32 identifier = IDC_NONE);
        /**
            Initialize the menu bar.

            @param hWnd
        */
        void SetJCS_MenuBar(HWND hWnd);
#endif // _WIN32


        /** getter **/
#ifdef _WIN32
        /**  */
        HMENU GetMenuBar() const { return this->m_menubar; }
#endif // _WIN32

    };

}

#endif // __JCS_MENUBAR_H__

