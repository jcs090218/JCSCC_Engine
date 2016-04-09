/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_COMPONENT_H__
#define __JCS_COMPONENT_H__

namespace JCS_GameInterface
{
    //-----------------------------------------------------------------------------------------------------------
    // JCS_Component
    // 
    // Desc : Interface of all Component
    //-----------------------------------------------------------------------------------------------------------
    struct JCS_Component
    {
        virtual ~JCS_Component() { }
    };

}

typedef JCS_GameInterface::JCS_Component JCS_Component;

#endif // __JCS_COMPONENT_H__

