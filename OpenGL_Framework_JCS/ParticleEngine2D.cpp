#include "ParticleEngine2D.h"


#include "SpriteBatch.h"
#include "ParticleBatch2D.h"

namespace JCS_OpenGLEngine
{
    ParticleEngine2D::ParticleEngine2D()
        : m_batches()
    {

    }

    ParticleEngine2D::~ParticleEngine2D()
    {
        for (auto& b : m_batches) 
            SafeDeleteObject(b);
    }

    void ParticleEngine2D::Update(float32 deltaTime)
    {
        for (auto& b : m_batches) 
            b->Update(deltaTime);
    }

    void ParticleEngine2D::Draw(SpriteBatch* spriteBatch)
    {
        spriteBatch->begin();

        for (auto& b : m_batches) 
            b->Draw(spriteBatch);

        spriteBatch->end();
        spriteBatch->renderBatch();
    }

    void ParticleEngine2D::addParticleBatch(ParticleBatch2D* particleBatch)
    {
        // Check if the Particle Batch are not nullptr...
        if (!particleBatch)
            return;

        m_batches.push_back(particleBatch);
    }

}

