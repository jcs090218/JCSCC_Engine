/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JCS_ScrollBar.h"


namespace JCS_GUI
{

    JCS_ScrollBar::JCS_ScrollBar()
    {

    }

    JCS_ScrollBar::~JCS_ScrollBar()
    {

    }

#ifdef _WIN32
    void JCS_ScrollBar::Create(const HWND hWnd, 
        const LPCWSTR word,
        const int32 x, const int32 y, 
        const int32 width, const int32 height, 
        const int32 identifier /*= IDC_NONE*/)
    {
        // Create the scroll bar.
        m_ownWindow = CreateWindowEx(
            0,                              // no extended styles 
            word,                           // scroll bar control class 
            (PTSTR)NULL,                    // no window text 
            WS_CHILD | WS_VISIBLE           // window styles  
            | SBS_HORZ,                     // horizontal scroll bar style 
            x,                              // horizontal position 
            y,                              // vertical position 
            width,                          // width of the scroll bar 
            height,                         // height of the scroll bar
            hWnd,                           // handle to main window 
            (HMENU)identifier,              // no menu 
            GetModuleHandle(NULL),          // instance owning this window 
            (PVOID)NULL);                   // pointer not needed 
    }
#endif // _WIN32

}

