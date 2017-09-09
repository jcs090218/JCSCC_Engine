/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_FILEDIALOGS_H__
/**
 * $File: JCS_FileDialog.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_FILEDIALOGS_H__

#include "JayCeS_StdAfx.h"

namespace JayCeS
{

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_FileDialog
    //
    // Description : Provide cross platform dialog type.
    //====================================================================================---------------------------------------------------------------
    class JCS_FileDialog
    {
    public:
        wchar_t fileName[MAX_PATH];

    public:
        JCS_FileDialog();
        ~JCS_FileDialog();

#ifdef _WIN32

#ifdef _UNICODE
        /**
            OpenFileDialog
                * Tutorials: 
                    - http://www.winprog.org/tutorial/app_two.html
                * MSDN: 
                    - https://msdn.microsoft.com/zh-tw/library/windows/desktop/ms646829(v=vs.85).aspx#open_file
        */ 
        bool OpenFileDialog(const HWND hWnd, const LPCWSTR title,
            const LPCWSTR filter, const LPCWSTR extension);
#else
        /** Comment are in _UNICODE session.**/
        bool OpenFileDialog(const HWND hWnd, const LPCSTR title,
            const LPCSTR filter, const LPCSTR extension);

#endif
#endif // _WIN32

    };
}

typedef JayCeS::JCS_FileDialog JCS_FileDialog;

#endif // __JCS_FILEDIALOGS_H__

