#ifndef __AUDIOXML_LOADER_H__
/**
 * $File: AudioXML_Loader.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __AUDIOXML_LOADER_H__


#include <GameInterface_JCS\JCS_XML_Loader.h>

namespace JCS_GameTool
{
    //====================================================================================
    // Class Name : AudioXML_Loader
    // 
    // Description : Load Audio XML Data into the program
    // Target : 1) Directory Path
    //          2) Filename
    //====================================================================================
    class AudioXML_Loader
        : public JCS_XML_Loader
    {
    public:
        explicit AudioXML_Loader();
        virtual ~AudioXML_Loader();

        /**
            Load XML data in to program in JCSCC audio xml format.

            @param name of the file.
            @param base name of the xml data.
        */
        virtual void LoadXML(const wchar_t* filename, const wchar_t* basename) override;
    };
}

typedef JCS_GameTool::AudioXML_Loader AudioXML_Loader;

#endif // __AUDIOXML_LOADER_H__

