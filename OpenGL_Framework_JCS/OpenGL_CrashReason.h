#ifndef __OPENGL_CRASHREASON_H__
/**
 * $File: OpenGL_CrashReason.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __OPENGL_CRASHREASON_H__



#include <JayCeS_JCS\JayCeS.h>

namespace JCS_OpenGLEngine
{

    //====================================================================================
    // Name : CrashReason
    // 
    // Description : List of all the reason might crashed the framework
    //        and handle it with error message.
    //====================================================================================
    enum class CrashReason
    {
        // Warnings
        WARN_LOADING_IMAGE = 101,
        WARN_LOADING_SOUND = 102,

        // Errors
        ERROR_LOADING_IMAGE = 201,
        ERROR_LOADING_SOUND = 202
    };

    /**
    * Function Name : JCS_CR (JCS_CrashReason)
    *
    * Description : Pass in the reason and Message Box the client.
    */
    inline void JCS_CR(CrashReason reason)
    {
#ifdef _WIN32
#ifdef _UNICODE
        switch (reason)
        {
            ////// Warnings ////////////
        case CrashReason::WARN_LOADING_IMAGE:
            JCS_MessageBox(L"Warning", L"Warning loading image...", MB_ICONWARNING);
            break;
        case CrashReason::WARN_LOADING_SOUND:
            JCS_MessageBox(L"Warning", L"Warning loading sound...", MB_ICONWARNING);
            break;

            /////// Errors ////////////
        case CrashReason::ERROR_LOADING_IMAGE:
            JCS_MessageBox(L"Error", L"Error loading image...", MB_ICONERROR);
            break;
        case CrashReason::ERROR_LOADING_SOUND:
            JCS_MessageBox(L"Error", L"Error loading sound...", MB_ICONERROR);
            break;
        }
#else
        // TODO(JenChieh): Finish ASCII version
        switch (reason)
        {
            ////// Warnings ////////////
        case CrashReason::WARN_LOADING_IMAGE:
            JCS_MessageBox("Warning", "Warning loading image", MB_ICONWARNING);
            break;
        case CrashReason::WARN_LOADING_SOUND:
            JCS_MessageBox("Warning", "Warning loading sound...", MB_ICONWARNING);
            break;
            /////// Errors ////////////
        case CrashReason::ERROR_LOADING_IMAGE:
            JCS_MessageBox("Error", "Error loading image...", MB_ICONERROR);
            break;
        case CrashReason::ERROR_LOADING_SOUND:
            JCS_MessageBox("Error", "Error loading sound...", MB_ICONERROR);
            break;
        }
#endif // _UNICODE
#elif _OSX

#else // Cross Platform

#endif

    }

}


#endif // __OPENGL_CRASHREASON_H__

