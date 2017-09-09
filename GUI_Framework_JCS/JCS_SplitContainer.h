#ifndef __JCS_SPLITCONTAINER_H__
/**
 * $File: JCS_SplitContainer.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_SPLITCONTAINER_H__



#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_SplitContainer
    //
    // Description : JCSCC Splite Contianer GUI.
    //====================================================================================---------------------------------------------------------------
    class JCS_SplitContainer
        : public JCS_WindowHandle
    {
    public:
        JCS_SplitContainer();
        ~JCS_SplitContainer();


#ifdef _WIN32
        

#endif // _WIN32
    };

}

typedef JCS_GUI::JCS_SplitContainer JCS_SplitContainer;

#endif // __JCS_SPLITCONTAINER_H__
