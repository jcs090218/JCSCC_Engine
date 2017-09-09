/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GLTEXTURE_H__
#define __GLTEXTURE_H__

#include "OpenGL_StdAfx.h"

namespace JCS_OpenGLEngine
{

    //====================================================================================-----------------------
    // Name : GLTexture
    // 
    // Description : 
    //====================================================================================-----------------------
    struct GLTexture
    {
        GLuint id;
        int32 width;
        int32 height;

    };

}

#endif // __GLTEXTURE_H__

