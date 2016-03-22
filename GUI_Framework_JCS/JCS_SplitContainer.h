#ifndef __JCS_SPLITCONTAINER_H__
#define __JCS_SPLITCONTAINER_H__



#include "GUI_StdAfx.h"

namespace JCS_GUI
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_SplitContainer
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
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

