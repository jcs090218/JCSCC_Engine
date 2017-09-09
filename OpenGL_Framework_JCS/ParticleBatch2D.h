#ifndef __PARTICLEBATCH2D_H__
#define __PARTICLEBATCH2D_H__


#include "Particle2D.h"

namespace JCS_OpenGLEngine
{
    class SpriteBatch;
    
    inline void defaultParticleUpdate(Particle2D& particle, float32 deltaTime) 
    {
        particle.position += particle.velocity * deltaTime;
    }

    //====================================================================================-----------------------
    // Name : ParticleBatch2D
    // 
    // Description : 
    //====================================================================================-----------------------
    class ParticleBatch2D
    {
    private:
        int32 findFreeParticle();

        Particle2D* m_pParticles;

        int32 m_maxParticles;
        int32 m_lastFreeParticle;
        float32 m_decayRate;

        GLTexture m_texture;

        std::function<void(Particle2D&, float32)> m_updateFunc;

    public:
        ParticleBatch2D();
        ~ParticleBatch2D();

        void Initialize(int32 maxParticles,
            float32 decayRate,
            GLTexture texture, 
            std::function<void(Particle2D&, float32)> updateFunc);
        void Update(float32 deltaTime);
        void Draw(SpriteBatch* spriteBatch);

        void AddParticle(const glm::vec2& position,
            const glm::vec2& velocity,
            const ColorRGBA8& color,
            float32 liftTime,
            float32 width);
    };

}

#endif // __PARTICLEBATCH2D_H__

