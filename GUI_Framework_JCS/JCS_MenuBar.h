#ifndef __JCS_MENUBAR_H__
#define __JCS_MENUBAR_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_MenuBar
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_MenuBar
        : public JCS_WindowHandle
    {
    private:
        HMENU m_menubar;

    public:
        JCS_MenuBar();
        ~JCS_MenuBar();

#ifdef _WIN32
        void AddMenuAttribute(const int32 menu, const LPCWSTR word);
        void AddFunctionAttribute(const LPCWSTR word, const int32 identifier = IDC_NONE);
        void SetJCS_MenuBar(HWND hWnd);
#endif // _WIN32


        // getter
#ifdef _WIN32
        HMENU GetMenuBar() const { return this->m_menubar; }
#endif // _WIN32

    };

}

#endif // __JCS_MENUBAR_H__

