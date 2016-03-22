#include "Animation2D.h"


#include "GraphicsD3D11.h"
#include "Sprite2D.h"

namespace JCS_D3DX_v11_Engine
{
    Animation2D::Animation2D(const wchar_t* basename, const wchar_t* filename, GraphicsD3D11& pDevice)
        : m_pDevice(pDevice)
        , m_origin()
        , m_delay(0)
        , m_frame(0)
        , m_animation()
        , m_xmlLoader()
        , m_frameCounter(0)
        , m_delayCounter(0)
    {
        // Load Sprites into Animation
        LoadAnimationSprite(basename);

        // Load XML data
        LoadAnimationXML(basename, filename);       /* "Character.jcs/normal_data" */
    }

    Animation2D::~Animation2D()
    {
        for(Sprite2D* pSprite : m_animation)
            SafeDeleteObject(pSprite);

        m_animation.clear();
    }

    //-----------------------------------------------------------------------------------
    // Load Animation Data into program and be ready to use
    // 
    // Format : ".img" -> ".xml"
    //-----------------------------------------------------------------------------------
    void Animation2D::LoadAnimationXML(const wchar_t* animationName, const wchar_t* path)
    {
        // Load XML
        m_xmlLoader.LoadXML(animationName, path);

        // Set Data
        std::vector<JCS_VECTOR2F> originData = m_xmlLoader.GetOrigins();
        this->m_delay = m_xmlLoader.GetDelay();
        this->m_frame = m_xmlLoader.GetTotalFrame();

        // Convert data into right form
        for (uint32 i = 0; i < originData.size(); ++i)
        {
            DirectX::SimpleMath::Vector2 targetForm;

            originData.at(i).x = targetForm.x;
            originData.at(i).y = targetForm.y;

            // Load Sprite before set data
            GetFrame(i)->SetOrigin(targetForm);
        }
    }

    //-----------------------------------------------------------------------------------
    // Load Animation Sprite into program and be ready to use
    //
    // Format : ".img" -> ".png"
    //-----------------------------------------------------------------------------------
    void Animation2D::LoadAnimationSprite(const wchar_t* animationName)
    {
        for (uint32 index = 0; index < m_frame; ++index)
        {
            // Format : example_0.png, example_1.png, example_2.png, etc.
            std::wstring t = std::wstring(animationName +
                std::wstring(L"_" + index) +
                std::wstring(L".png"));

            const wchar_t* c = t.c_str();

            Sprite2D* pSprite = new Sprite2D(m_pDevice, c);
            m_animation.push_back(pSprite);
        }
    }

    void Animation2D::DrawAnimation(DirectX::SpriteBatch& sprite_batch, bool loop)
    {
        // There is no animation loaded
        if (GetFrame() == 0)
            return;
        
        // Draw the frame
        DrawFrame(sprite_batch, m_frameCounter);

        // Animation Algorithm
        {
            if (m_delayCounter < GetDelay())
                ++m_delayCounter;
            else
            {
                ++m_frameCounter; 
                m_delayCounter = 0;
            }

            if (!loop)
                return;

            if (m_frameCounter > GetFrame())
                m_frameCounter = 0;
        }
    }

    //-----------------------------------------------------------------------------------
    // DrawFrame
    //
    // SpriteBatch : batch in order to render
    // int nFrame : specific number of frame
    // 
    // Desc : Draw Specific Frame
    //-----------------------------------------------------------------------------------
    void Animation2D::DrawFrame(DirectX::SpriteBatch& sprite_batch, const uint32 nFrame)
    {
        GetFrame(nFrame)->draw(sprite_batch);
    }

}

