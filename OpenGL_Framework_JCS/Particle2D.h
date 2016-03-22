#ifndef __PARTICLE2D_H__
#define __PARTICLE2D_H__


#include "OpenGL_StdAfx.h"

namespace JCS_OpenGLEngine
{

    //-----------------------------------------------------------------------------------------------------------
    // Name : Particle2D
    // 
    // Desc : 
    //-----------------------------------------------------------------------------------------------------------
    struct Particle2D
    {
        friend class ParticleBatch2D;

        glm::vec2 position = glm::vec2(0.0f, 0.0f);
        glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
        ColorRGBA8 color;
        float32 life = 0.0f;
        float32 width = 0.0f;
    };

}

#endif // __PARTICLE2D_H__

