#ifndef __API_Type_H__
/**
 * $File: API_Type.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __API_Type_H__


//-------------------------------------------------------------------------
// Any Render Devices should manage here.
//-------------------------------------------------------------------------
namespace JCS_GameInterface
{
    //====================================================================================
    // Enum Name : API_Type 
    //
    // Description : API in JCSCC.
    //====================================================================================
    enum class API_Type
    {
        NONE,

        DIRECT2D,
        DIRECTX3D_9,
        DIRECTX3D_11,
        OPENGL,
        SDL,
        VULKAN
    };

}

typedef JCS_GameInterface::API_Type API_Type;

#endif // __API_Type_H__

