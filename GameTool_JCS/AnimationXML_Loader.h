#ifndef __ANIMATIONXML_LOADER_H__
/**
 * $File: AnimationXML_Loader.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __ANIMATIONXML_LOADER_H__


#include <GameInterface_JCS\JCS_XML_Loader.h>
#include <vector>


namespace JCS_GameTool
{

    //====================================================================================
    // Class Name : AnimationXML_Loader
    // 
    // Description : Load Animation/Sprite XML Data into the program
    // Target : 1) Directory Path
    //          2) Filename
    //====================================================================================
    class AnimationXML_Loader
        : public JCS_XML_Loader
    {
    private:
        std::vector<JCS_VECTOR2F> m_origins;        // store all the sprite origin to animate
        uint32 m_delay;                             // delay for each frame
        uint32 m_totalFrame;                        // total frame in an animation

    public:
        explicit AnimationXML_Loader();
        virtual ~AnimationXML_Loader();

        /**
            Load XML data in to program in JCSCC animation/sprite xml format.

            @param name of the file.
            @param base name of the xml data.
        */
        virtual void LoadXML(const wchar_t* filename, const wchar_t* basename) override;

        /** setter **/
        void SetDelay(const uint32 delay) { this->m_delay = delay; }
        void SetTotalFrame(const uint32 frame) { this->m_totalFrame = frame; }

        /** getter **/
        std::vector<JCS_VECTOR2F> GetOrigins() const { return this->m_origins; }
        uint32 GetDelay() const { return this->m_delay; }
        uint32 GetTotalFrame() const { return this->m_totalFrame; }

    };

}

typedef JCS_GameTool::AnimationXML_Loader AnimationXML_Loader;

#endif // __ANIMATIONXML_LOADER_H__

