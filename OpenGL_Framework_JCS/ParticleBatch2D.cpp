#include "ParticleBatch2D.h"


#include "SpriteBatch.h"

namespace JCS_OpenGLEngine
{
    ParticleBatch2D::ParticleBatch2D()
        : m_texture()
        , m_pParticles(nullptr)
        , m_decayRate(0.1f)
        , m_maxParticles(0)
        , m_lastFreeParticle(0)
    {

    }

    ParticleBatch2D::~ParticleBatch2D()
    {
        SafeDeleteArrayObject(m_pParticles);
    }

    void ParticleBatch2D::Initialize(int32 maxParticles,
        float32 decayRate,
        GLTexture texture,
        std::function<void(Particle2D&, float32)> updateFunc /*= defaultParticleUpdate*/)
    {
        m_maxParticles = maxParticles;
        m_pParticles = new Particle2D[maxParticles];
        m_decayRate = decayRate;
        m_texture = texture;
        m_updateFunc = updateFunc;
    }

    void ParticleBatch2D::Update(float32 deltaTime)
    {
        for (int32 index = 0; index < m_maxParticles; ++index)
        {
            // Check if it is active
            if (m_pParticles[index].life <= 0.0f)
                continue;
            
            m_updateFunc(m_pParticles[index], deltaTime);
            m_pParticles[index].life -= m_decayRate * deltaTime;
        }
    }

    void ParticleBatch2D::Draw(SpriteBatch* spriteBatch)
    {
        glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

        for (int32 index = 0; 
            index < m_maxParticles; 
            ++index) 
        {
            auto& p = m_pParticles[index];

            // Check if it is active
            if (p.life <= 0.0f)
                continue;

            glm::vec4 destRect(p.position.x, p.position.y, p.width, p.width);
            spriteBatch->draw(destRect, uvRect, m_texture.id, 0.0f, p.color);
        }
    }

    void ParticleBatch2D::AddParticle(const glm::vec2& position,
        const glm::vec2& velocity,
        const ColorRGBA8& color,
        float32 liftTime,
        float32 width)
    {
        // This should spend approximate to O(1) time complexity.
        int32 particleIndex = findFreeParticle();

        auto& p = m_pParticles[particleIndex];

        p.life = liftTime;
        p.position = position;
        p.velocity = velocity;
        p.color = color;
        p.width = width;
    }

    int32 ParticleBatch2D::findFreeParticle()
    {
        int32 index;

        // [English] Use last free particle to find the nearest avaliable paritcle, 
        //          so often time it won't go through O(n) time complexity.
        //          It almost return in O(1) time complexity!
        //
        // [中文] 利用上一個找到的粒子標籤(m_lastFreeParticle), 來達到
        //        時間複雜度接近於 O(1)!!!
        {
            for (index = m_lastFreeParticle; 
                index < m_maxParticles; 
                ++index)
            {
                if (m_pParticles[index].life <= 0.0f)
                {
                    m_lastFreeParticle = index;
                    return index;
                }
            }
        }


        // [English] If we does not get the paritcle we want then we will have to 
        //          go loop through in O(n) time complexity...
        //          but in fact, this should not loop through complete linear time. 
        //          cuz next time should be at the first place cuz is free and ready 
        //          to be use already.
        // 
        //              - Time Compelxity: O(n), Ω(1)
        // 
        // [中文] 如果上一個loop已經超過的 粒子的上限數目, 則會開始回頭尋找第一個數目.
        //        這樣也才不會重覆到...
        // 
        //              - 時間複雜度: O(n), Ω(1)
        {
            for (index = 0; 
                index < m_lastFreeParticle; 
                ++index)
            {
                if (m_pParticles[index].life <= 0.0f)
                {
                    m_lastFreeParticle = index;
                    return index;
                }
            }
        }

        // [English] No particles are free, overwrite first particle. 
        //          But should not often happen except the lift time of the 
        //          particle is too long or the amount of the particle are too small.
        //          Either one of them!
        // 
        // [中文] 如果總粒子數量太少 或者 粒子效果時間太長
        //        都有可能發生這些事情
        return 0;
    }

}

