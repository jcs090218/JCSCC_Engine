#ifndef __JCS_COMPONENT_H__
/**
 * $File: JCS_Component.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_COMPONENT_H__


namespace JCS_GameInterface
{

    //====================================================================================-----------------------
    // JCS_Component
    // 
    // Description : Interface of all Component
    //====================================================================================-----------------------
    struct JCS_Component
    {
        virtual ~JCS_Component() { }
    };

}

typedef JCS_GameInterface::JCS_Component JCS_Component;

#endif // __JCS_COMPONENT_H__
