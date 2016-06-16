/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __AUDIOXML_LOADER_H__
#define __AUDIOXML_LOADER_H__

#include <GameInterface_JCS\JCS_XML_Loader.h>

namespace JCS_GameTool
{
    //-----------------------------------------------------------------------------
    // AudioXML_Loader
    // 
    // Desc : Load Data into the program
    // Target : 1) Directory Path
    //          2) Filename
    //-----------------------------------------------------------------------------
    class AudioXML_Loader
        : public JCS_XML_Loader
    {
    public:
        explicit AudioXML_Loader();
        virtual ~AudioXML_Loader();

        virtual void LoadXML(const wchar_t* filename, const wchar_t* basename) override;
    };
}

typedef JCS_GameTool::AudioXML_Loader AudioXML_Loader;

#endif // __AUDIOXML_LOADER_H__

