#ifndef __JCS_BUTTON_H__
/**
 * $File: JCS_PushButton.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_BUTTON_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_PushButton
    //
    // Description : JCSCC Push Button GUI.
    //====================================================================================---------------------------------------------------------------
    class JCS_PushButton
        : public JCS_WindowHandle
    {
    public:
        JCS_PushButton();
        ~JCS_PushButton();

#ifdef _WIN32
        /**
            Create GUI.

            @param hWnd
            @param word
            @param x
            @param y
            @param width
            @param height
            @param identifier
        */
        void Create(const HWND hWnd, 
            const LPCWSTR word, 
            const int32 x, const int32 y,
            const int32 width, const int32 height, 
            const int32 identifier = IDC_NONE);
#endif // _WIN32
    };

}

#endif // __JCS_BUTTON_H__

