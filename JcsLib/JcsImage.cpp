/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JcsImage.h"

#include "IJcsImageProperty.h"

namespace JcsLib
{

    JcsImage::JcsImage()
        : m_checksum(0)
        , m_headerOffset(0)
        , m_offset(0)
        , m_parsed(false)
        , m_properties()
        , m_size(-1)
    {

    }

    JcsImage::JcsImage(wchar_t* name)
        : m_checksum(0)
        , m_headerOffset(0)
        , m_offset(0)
        , m_parsed(false)
        , m_properties()
        , m_size(-1)
    {
        // m_name is at "IJcsObject"
        m_name = name;
    }

    JcsImage::~JcsImage()
    {

    }

    JcsImage* JcsImage::Clone()
    {
        return nullptr;
    }

    void JcsImage::AddProperty(IJcsImageProperty prop)
    {

    }

    void JcsImage::Dispose()
    {

    }

    std::wstring JcsImage::DumpBlock()
    {
        return L"";
    }

    void JcsImage::ParseImage()
    {

    }

    void JcsImage::RemoveProperty(wchar_t* name)
    {

    }

    void JcsImage::SaveImage(/*BinaryWriter jcsWriter*/)
    {

    }

}

