/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCSIMAGE_H__
#define __JCSIMAGE_H__


#include "JcsLib_StdAfx.h"

#include "IJcsObject.h"

namespace JcsLib
{
    class IJcsImageProperty;

    //------------------------------------------------------------------------------------
    // Name : JcsImage (Data Type)
    //
    // Desc : Image Data type
    //------------------------------------------------------------------------------------
    class JcsImage
        : public IJcsObject
    {
    private:
        int32 m_checksum;
        uint32 m_headerOffset;
        uint32 m_offset;
        bool m_parsed;
        std::list<IJcsImageProperty*> m_properties;
        int32 m_size;

    public:
        JcsImage();
        JcsImage(wchar_t* name);
        virtual  ~JcsImage();

        JcsImage* Clone();
        void AddProperty(IJcsImageProperty prop);
        void Dispose();
        std::wstring DumpBlock();
        void ParseImage();
        void RemoveProperty(wchar_t* name);
        void SaveImage(/*BinaryWriter jcsWriter*/);


        // setter
        void SetSize(const int32 size) { this->m_size = size; }
        void SetChecksum(const int32 checksum) { this->m_checksum = checksum; }
        
        // getter
        int32 GetSize() const { return this->m_size; }
        int32 GetChecksum() const { return this->m_checksum; }

    };

}

#endif // __JCSIMAGE_H__

