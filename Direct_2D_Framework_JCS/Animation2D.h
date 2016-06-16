/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_ANIMATION2D_H__
#define __D2D_ANIMATION2D_H__

#include "D2D_StdAfx.h"
#include <vector>
#include <GameTool_JCS\AnimationXML_Loader.h>

namespace JCS_D2DEngine
{
    class Sprite2D;
    class Graphics2D;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Animation2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Animation2D
    {
    private:
        Graphics2D& m_pDevice;

        JCS_VECTOR2F m_origin;      // animation origin or position (threat this as texture)
        uint32 m_delay;
        uint32 m_frame;

        uint32 m_frameCounter;
        uint32 m_delayCounter;

        // Sprites Data
        std::vector<Sprite2D*> m_animation;

        // Each Sprite's Origin Data
        std::vector<JCS_VECTOR2F> m_spriteOrigin;

        // XML Loader
        AnimationXML_Loader m_xmlLoader;

    public:
        Animation2D(wchar_t* basename, wchar_t* filename, Graphics2D& device);
        virtual ~Animation2D();

        void DrawAnimation(bool loop = true);

        // setter
        void SetAnimationOrigin(const JCS_VECTOR2F origin) { this->m_origin = origin; }
        void SetDelay(const uint32 delay) { this->m_delay = delay; }
        void SetFrame(const uint32 frame) { this->m_frame = frame; }

        // getter
        JCS_VECTOR2F GetAnimationOrigin() const { return this->m_origin; }
        uint32 GetDelay() const { return this->m_delay; }
        uint32 GetFrame() const { return this->m_frame; }

    private:
        void DrawFrame(const JCS_VECTOR2F origin, const uint32 nFrame);
        JCS_VECTOR2F GetOriginData(const uint32 index) const;

        void LoadAnimationXML(wchar_t* animationName, wchar_t* filename);
        void LoadAnimationSprite(wchar_t* animationName);
    };

}

#endif // __D2D_ANIMATION2D_H__

