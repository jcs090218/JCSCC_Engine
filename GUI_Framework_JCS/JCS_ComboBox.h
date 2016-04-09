/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_COMBOBOX_H__
#define __JCS_COMBOBOX_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_ComboBox
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_ComboBox
        : public JCS_WindowHandle
    {
    public:
        JCS_ComboBox();
        ~JCS_ComboBox();

#ifdef _WIN32
        void Create(const HWND hWnd,
            const LPCWSTR word,
            const int32 x, const int32 y,
            const int32 width, const int32 height,
            const int32 identifier = IDC_NONE);
#endif // _WIN32
    };

}

typedef JCS_GUI::JCS_ComboBox JCS_ComboBox;

#endif // __JCS_COMBOBOX_H__

