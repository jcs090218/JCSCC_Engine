/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SOCKET_CRASHREASON_H__
#define __SOCKET_CRASHREASON_H__



#include <JayCeS_JCS\JayCeS.h>

namespace JCS_Network
{

    //------------------------------------------------------------------------------------
    // Name : CrashReason
    // 
    // Desc : List of all the reason might crashed the framework
    //        and handle it with error message.
    //------------------------------------------------------------------------------------
    enum class CrashReason
    {
        // Warnings

        // Errors
        ERROR_PORT_REUSE = 201
    };

    /**
    * Function Name : JCS_CR (JCS_CrashReason)
    *
    * Desc : Pass in the reason and Message Box the client.
    */
    inline void JCS_CR(CrashReason reason)
    {
#ifdef _UNICODE
        switch (reason)
        {
            ////// Warnings ////////////


            /////// Errors ////////////
        case CrashReason::ERROR_PORT_REUSE:
            JCS_MessageBox(L"Error", L"Port is used already...", MB_ICONERROR);
            break;

        }
#else
        // TODO(JenChieh): Finish ASCII version
        switch (reason)
        {
            ////// Warnings ////////////


            /////// Errors ////////////
        case CrashReason::ERROR_PORT_REUSE:
            JCS_MessageBox("Error", "Port is used already...", MB_ICONERROR);
            break;

        }
#endif
    }

}


#endif // __SOCKET_CRASHREASON_H__

