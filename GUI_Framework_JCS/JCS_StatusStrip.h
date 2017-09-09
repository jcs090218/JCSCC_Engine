#ifndef __JCS_STATUSSTRIP_H__
/**
 * $File: JCS_StatusStrip.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_STATUSSTRIP_H__


#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_StatusStrip
    //
    // Description : JCSCC Status Strip GUI.
    //====================================================================================---------------------------------------------------------------
    class JCS_StatusStrip
        : public JCS_WindowHandle
    {
    public:
        JCS_StatusStrip();
        ~JCS_StatusStrip();

#ifdef _WIN32

#endif // _WIN32
    };

}

#endif // __JCS_STATUSSTRIP_H__
