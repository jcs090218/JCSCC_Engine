#ifndef __API_Type_H__
#define __API_Type_H__


//-------------------------------------------------------------------------
// Any Render Devices should manage here.
//-------------------------------------------------------------------------
namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // Name : API_Type 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    enum class API_Type
    {
        NONE,
        DIRECT2D,
        DIRECTX3D_9,
        DIRECTX3D_11,
        OPENGL,
        SDL
    };

}

typedef JCS_GameInterface::API_Type API_Type;

#endif // __API_Type_H__

