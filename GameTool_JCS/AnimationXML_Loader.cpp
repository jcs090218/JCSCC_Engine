/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "AnimationXML_Loader.h"

#include "GameTool_StdAfx.h"

#include <iostream>

namespace JCS_GameTool
{
    AnimationXML_Loader::AnimationXML_Loader()
        : m_origins()
        , m_totalFrame(0)
        , m_delay(0)
    {
        
    }

    AnimationXML_Loader::~AnimationXML_Loader()
    {

    }

    void AnimationXML_Loader::LoadXML(const wchar_t* filename, const wchar_t* basename)
    {
        // set file path
        std::wstring ws1(filename);
        std::string path1(ws1.begin(), ws1.end());
        std::string path = "jcs/" + path1 + ".xml";

        // create xml document and ready to read xml file
        rapidxml::xml_document<> xmlFile;
        std::ifstream file(path);
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        std::string content(buffer.str());
        xmlFile.parse<0>(&content[0]);

        rapidxml::xml_node<>* pRoot = xmlFile.first_node();

        // Convert wchar_t* to string
        std::wstring ws(basename);
        std::string basenameStr(ws.begin(), ws.end());


        bool sequence = false;      // this force us have to have to set the same animation in a role
        uint32 totalFrame = 0;      // total frame in a sequence of animation
        rapidxml::xml_attribute<>* pAttr;

        for (rapidxml::xml_node<>* pNode = pRoot->first_node("i"); 
            pNode; 
            pNode = pNode->next_sibling()) 
        {
            // Get the image attribute
            pAttr = pNode->first_attribute("image");
            std::string strValue = pAttr->value();

            // Compare to see the attribute are correct
            if (strValue != basenameStr)
            {
                if (sequence) 
                    break;
                continue;
            }

            // Find and Set delay
            pAttr = pNode->first_attribute("delay");
            this->SetDelay(atoi(pAttr->value()));

            // Find and Set Origin
            JCS_VECTOR2F tempOrigin;
            pAttr = pNode->first_attribute("x");
            tempOrigin.x = strtof(pAttr->value(), NULL);
            pAttr = pNode->first_attribute("y");
            tempOrigin.y = strtof(pAttr->value(), NULL);

            m_origins.push_back(tempOrigin);

            ++totalFrame;
            sequence = true;
        }

        // Set the total frame
        this->SetTotalFrame(totalFrame);
    }

}

