/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_BUFFERBUILDER_H__
/**
 * $File: JCS_BufferBuilder.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_BUFFERBUILDER_H__


#include "JCS_Buffer.h"

namespace JayCeS
{

    //====================================================================================---------------------------------------------------------------
    // Name : JCS_BufferBuilder
    //
    // Description : 
    //====================================================================================---------------------------------------------------------------
    class JCS_BufferBuilder
    {
    private:
        JCS_Buffer* m_jcsBuf = nullptr;

    public:
        JCS_BufferBuilder();
        ~JCS_BufferBuilder();


        void WriteByte8(byte buf);
        void WriteChar8(char buf);
        void WriteShort16(int16 buf);
        void WriteInt32(int32 buf);
        void WriteUInt32(uint32 buf);
        void WriteInt64(int64 buf);
        void WriteUInt64(uint64 buf);
        void WriteFloat32(float32 buf);
        void WriteFloat64(float64 buf);

        byte ReadByte8();
        char ReadChar8();
        int16 ReadShort16();
        int32 ReadInt32();
        int64 ReadInt64();
        uint32 ReadUInt32();
        uint64 ReadUInt64();
        float32 ReadFloat32();
        float64 ReadFloat64();

        void ClearBuffer();
#ifdef _WIN32
        // Print out all the buffer in the current builder.
        void PeekBuffer();
#endif // _WIN32

        /** setter **/ 

        /** getter **/
        size_t GetLength() const { return this->m_jcsBuf->GetLength(); }
        JCS_Buffer* GetJcsBuffer() const { return this->m_jcsBuf; }
        JCS_Buffer& GetJcsBufferRef() const { return *(this->m_jcsBuf); }
        std::queue<byte>& GetBuffer() { return this->m_jcsBuf->GetBuffer(); }

    };

}

typedef JayCeS::JCS_BufferBuilder JCS_BufferBuilder;

#endif // __JCS_BUFFERBUILDER_H__

