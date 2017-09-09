/**
 * $File: Animation2D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Animation2D.h"

#include "Sprite2D.h"
#include "Graphics2D.h"

namespace JCS_D2DEngine
{
    Animation2D::Animation2D(wchar_t* basename, wchar_t* filename, Graphics2D& device)
        : m_pDevice(device)
        , m_animation()
        , m_origin()
        , m_spriteOrigin()
        , m_frame(0)
        , m_xmlLoader()
        , m_frameCounter(0)
        , m_delayCounter(0)
    {
        // Load XML data
        LoadAnimationXML(basename, filename);       /* "Character.jcs/normal_data" */

        // Load Sprites into Animation
        LoadAnimationSprite(basename);
    }

    Animation2D::~Animation2D()
    {
        for (Sprite2D* pSprite2D : m_animation)
            SafeDeleteObject(pSprite2D);

        m_animation.clear();
        m_spriteOrigin.clear();
    }

    //-----------------------------------------------------------------------------------
    // Load Animation Data into program and be ready to use
    // 
    // Format : ".img" -> ".xml"
    //-----------------------------------------------------------------------------------
    void Animation2D::LoadAnimationXML(wchar_t* animationName, wchar_t* path)
    {
        // Load XML
        m_xmlLoader.LoadXML(animationName, path);

        // Set Data
        m_spriteOrigin = m_xmlLoader.GetOrigins();
        this->m_delay = m_xmlLoader.GetDelay();
        this->m_frame = m_xmlLoader.GetTotalFrame();
    }

    //-----------------------------------------------------------------------------------
    // Load Animation Sprite into program and be ready to use
    //
    // Format : ".img" -> ".png"
    //-----------------------------------------------------------------------------------
    void Animation2D::LoadAnimationSprite(wchar_t* animationName)
    {
        for (uint32 index = 0; index < m_frame; ++index)
        {
            // Format : example_0.png, example_1.png, example_2.png, etc.
            std::wstring t = std::wstring(animationName +
                std::wstring(L"_" + index) + 
                std::wstring(L".png"));
            
            Sprite2D* pSprite2D = new Sprite2D((wchar_t*)(t.c_str()), m_pDevice);
            m_animation.push_back(pSprite2D);
        }
    }

    void Animation2D::DrawAnimation(bool loop)
    {
        DrawFrame(GetOriginData(m_frameCounter), m_frameCounter);

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

    JCS_VECTOR2F Animation2D::GetOriginData(const uint32 index) const 
    { 
        return m_spriteOrigin.at(index); 
    }

    //-----------------------------------------------------------------------------------
    // DrawFrame
    //
    // int x : origin x
    // int y : origin y
    // int nFrame : specific number of frame
    // 
    // Description : Draw Specific Frame
    //-----------------------------------------------------------------------------------
    void Animation2D::DrawFrame(const JCS_VECTOR2F origin, const uint32 nFrame)
    {
        m_animation.at(nFrame)->SetOrigin(origin);
        m_animation.at(nFrame)->draw();
    }

}

