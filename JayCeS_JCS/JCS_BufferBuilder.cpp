/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JCS_BufferBuilder.h"


#include "JCS_Buffer.h"

namespace JayCeS
{

    JCS_BufferBuilder::JCS_BufferBuilder()
    {
        m_jcsBuf = new JCS_Buffer;
    }

    JCS_BufferBuilder::~JCS_BufferBuilder()
    {
        ClearBuffer();
    }

    void JCS_BufferBuilder::ClearBuffer()
    { 
        SafeDeleteObject(m_jcsBuf);
    }

#ifdef _WIN32
    void JCS_BufferBuilder::PeekBuffer()
    {
        if (GetBuffer().empty())
        {
            JCS_Error(L"JCS_BufferBuilder is empty.");
            return;
        }

        /* 
            * Information: 
            http://stackoverflow.com/questions/12631514/how-can-i-print-out-the-contents-of-stdstack-and-return-its-size
        */
        int count = 0;
        for (std::queue<byte> dump = GetBuffer();
            !dump.empty();
            dump.pop())
        {
            if ((count % 20) == 0 && 
                count != 0)
            {
                JCS_Print1(L"%c\n", dump.front());
            }
            else 
            {
                JCS_Print1(L"%c ", dump.front());
            }
            ++count;
        }
        JCS_Print(L"\n");
    }
#endif // _WIN32

    // 
    void JCS_BufferBuilder::WriteByte8(byte buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteChar8(char buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteShort16(int16 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteInt32(int32 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteUInt32(uint32 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteInt64(int64 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteUInt64(uint64 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    void JCS_BufferBuilder::WriteFloat32(float32 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }
    
    void JCS_BufferBuilder::WriteFloat64(float64 buf)
    {
        m_jcsBuf->AddBuf(buf);
    }

    byte JCS_BufferBuilder::ReadByte8()
    {
        return GetJcsBuffer()->RemoveBuffer();
    }
    char JCS_BufferBuilder::ReadChar8()
    {
        return (char)GetJcsBuffer()->RemoveBuffer();
    }
    int16 JCS_BufferBuilder::ReadShort16()
    {
        int16 buffer = (int16)(ReadByte8() | (ReadByte8() << 8));
        return buffer;
    }
    int32 JCS_BufferBuilder::ReadInt32()
    {
        int32 buffer = (int32)(
            ReadByte8() | 
            (ReadByte8() << 8) | 
            (ReadByte8() << 16) | 
            (ReadByte8() << 24)
            );
        return buffer;
    }
    uint32 JCS_BufferBuilder::ReadUInt32()
    {
        uint32 buffer = (uint32)(
            ReadByte8() |
            (ReadByte8() << 8) |
            (ReadByte8() << 16) |
            (ReadByte8() << 24)
            );
        return buffer;
    }
    int64 JCS_BufferBuilder::ReadInt64()
    {
        int64 buffer = (int64)(
            ReadInt32() |
            (((int64)ReadInt32()) << 32));
        return buffer;
    }
    uint64 JCS_BufferBuilder::ReadUInt64()
    {
        uint64 buffer = (uint64)(
            ReadInt32() |
            (((uint64)ReadInt32()) << 32));
        return buffer;
    }
    float32 JCS_BufferBuilder::ReadFloat32()
    {
        // According how we split float32 into byte, 
        // we return byte back to float32
        JCS_FLOAT32 jf32;
        jf32.buffer.bytes[0] = ReadByte8();
        jf32.buffer.bytes[1] = ReadByte8();
        jf32.buffer.bytes[2] = ReadByte8();
        jf32.buffer.bytes[3] = ReadByte8();

        return jf32.buffer.f;
    }
    float64 JCS_BufferBuilder::ReadFloat64()
    {
        // According how we split float64 into byte, 
        // we return byte back to float64
        JCS_FLOAT64 jf64;
        jf64.buffer.bytes[0] = ReadByte8();
        jf64.buffer.bytes[1] = ReadByte8();
        jf64.buffer.bytes[2] = ReadByte8();
        jf64.buffer.bytes[3] = ReadByte8();
        jf64.buffer.bytes[4] = ReadByte8();
        jf64.buffer.bytes[5] = ReadByte8();
        jf64.buffer.bytes[6] = ReadByte8();
        jf64.buffer.bytes[7] = ReadByte8();

        return jf64.buffer.f;
    }

}

