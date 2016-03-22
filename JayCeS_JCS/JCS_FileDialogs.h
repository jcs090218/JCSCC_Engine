#ifndef __JCS_FILEDIALOGS_H__
#define __JCS_FILEDIALOGS_H__

#include "JayCeS_StdAfx.h"

namespace JayCeS
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_FileDialog
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
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

