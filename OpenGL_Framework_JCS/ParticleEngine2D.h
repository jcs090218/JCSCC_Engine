#ifndef __PARTICLEENGINE2D_H__
#define __PARTICLEENGINE2D_H__


#include "OpenGL_StdAfx.h"

namespace JCS_OpenGLEngine
{
    class ParticleBatch2D;
    class SpriteBatch;

    //====================================================================================-----------------------
    // Name : ParticleEngine2D
    // 
    // Description : 
    //====================================================================================-----------------------
    class ParticleEngine2D
    {
    private:
        std::vector<ParticleBatch2D*> m_batches;

    public:
        ParticleEngine2D();
        ~ParticleEngine2D();

        void Update(float32 deltaTime);
        void Draw(SpriteBatch* spriteBatch);

        // After adding a particle batch, the ParticleEngine2D becomes
        // responsible for deallocation.
        void addParticleBatch(ParticleBatch2D* particleBatch);
    };

}

#endif // __PARTICLEENGINE2D_H__

