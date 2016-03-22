#include "AudioXML_Loader.h"


namespace JCS_GameTool
{
    AudioXML_Loader::AudioXML_Loader()
    {
        
    }

    AudioXML_Loader::~AudioXML_Loader()
    {

    }

    void AudioXML_Loader::LoadXML(const wchar_t* filename, const wchar_t* basename)
    {
        // set file path
        std::wstring ws(filename);
        std::string tempFilename(ws.begin(), ws.end());
        std::string path = "jcs/Sound.jcs/" + tempFilename + ".xml";

        // create xml document and ready to read xml file
        rapidxml::xml_document<> xmlFile;
        std::ifstream file(path);       // set to read
        std::stringstream buffer;       // input buffer
        buffer << file.rdbuf();
        file.close();
        std::string content(buffer.str());
        xmlFile.parse<0>(&content[0]);

        rapidxml::xml_node<>* pRoot = xmlFile.first_node();

    }

}

