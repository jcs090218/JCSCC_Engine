/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JCS_MenuBar.h"


namespace JCS_GUI
{

    JCS_MenuBar::JCS_MenuBar()
        : m_menubar(CreateMenu())
    {

    }

    JCS_MenuBar::~JCS_MenuBar()
    {

    }

#ifdef _WIN32
    void JCS_MenuBar::AddMenuAttribute(const int32 menu,
        const LPCWSTR word)
    {
        AppendMenu(GetMenuBar(), MF_POPUP, menu, word);
    }
    void JCS_MenuBar::AddFunctionAttribute(const LPCWSTR word, 
        const int32 identifier /*= IDC_NONE*/)
    {
        AppendMenu(GetMenuBar(), MF_POPUP, identifier, word);
    }
    void JCS_MenuBar::SetJCS_MenuBar(HWND hWnd)
    {
        SetMenu(hWnd, GetMenuBar());
    }
#endif // _WIN32

}

