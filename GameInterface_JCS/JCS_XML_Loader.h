#ifndef __JCS_XML_LOADER_H__
/**
 * $File: JCS_XML_Loader.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_XML_LOADER_H__


#include "GameInterface_StdAfx.h"
#include <GameTool_JCS\rapidxml\rapidxml.hpp>
#include <GameTool_JCS\rapidxml\rapidxml_iterators.hpp>
#include <GameTool_JCS\rapidxml\rapidxml_print.hpp>
#include <GameTool_JCS\rapidxml\rapidxml_utils.hpp>
#include <sstream>

namespace JCS_GameInterface
{
    class JCS_XML_Loader
    {
    public:
        virtual ~JCS_XML_Loader() { }

        virtual void LoadXML(const wchar_t* filename, const wchar_t* basename) = 0;
    };
}

typedef JCS_GameInterface::JCS_XML_Loader JCS_XML_Loader;

#endif // __JCS_XMLLOADER_H__

