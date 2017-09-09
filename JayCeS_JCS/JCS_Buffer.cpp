/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

/**
 * $File: JCS_Buffer.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JCS_Buffer.h"


namespace JayCeS
{

    JCS_Buffer::JCS_Buffer()
        : m_buffer()
    {
        
    }

    JCS_Buffer::~JCS_Buffer()
    {
        ClearBuffer();
    }

    void JCS_Buffer::ClearBuffer()
    {
        // Clear all the data.
        while (!GetBuffer().empty())
            GetBuffer().pop();
    }

    void JCS_Buffer::AddBuffer(byte buf, const size_t len)
    {
        m_buffer.push(buf);
    }
    byte JCS_Buffer::RemoveBuffer()
    {
        // Check empty
        if (GetBuffer().empty())
        {
            throw JCS_Error(L"Buffer is empty...");
            return 0;
        }

        byte buffer = GetBuffer().front();    // get the front element
        GetBuffer().pop();     // delete the front element

        return buffer;
    }

    void JCS_Buffer::AddBuf(byte buf)
    {
        AddBuffer((byte)buf, sizeof(byte));
    }
    void JCS_Buffer::AddBuf(char buf)
    {
        AddBuffer((byte)buf, sizeof(char));
    }
    void JCS_Buffer::AddBuf(int16 buf)
    {
        byte first = (byte)buf, second = (byte)(buf >> 8);

        AddBuffer(first, sizeof(int16));
        AddBuffer(second, sizeof(int16));
    }
    void JCS_Buffer::AddBuf(uint16 buf)
    {
        AddBuf((int16)buf);
    }
    void JCS_Buffer::AddBuf(int32 buf)
    {
        byte b1, b2, b3, b4;
        b1 = (byte)buf;
        b2 = (byte)(buf >> 8);
        b3 = (byte)(buf >> 16);
        b4 = (byte)(buf >> 24);

        AddBuffer(b1, sizeof(int32));
        AddBuffer(b2, sizeof(int32));
        AddBuffer(b3, sizeof(int32));
        AddBuffer(b4, sizeof(int32));
    }
    void JCS_Buffer::AddBuf(uint32 buf)
    {
        AddBuf((int32)buf);
    }
    void JCS_Buffer::AddBuf(float32 buf)
    {
        // Assign data
        JCS_FLOAT32 data(buf);

        // put the float32 into single byte
        byte b1, b2, b3, b4;
        b1 = data.buffer.bytes[0];
        b2 = data.buffer.bytes[1];
        b3 = data.buffer.bytes[2];
        b4 = data.buffer.bytes[3];

        // add byte into the buffer array! (this builder)
        AddBuffer(b1, sizeof(float32));
        AddBuffer(b2, sizeof(float32));
        AddBuffer(b3, sizeof(float32));
        AddBuffer(b4, sizeof(float32));
    }
    void JCS_Buffer::AddBuf(int64 buf)
    {
        int32 b64, b32;      // first half of bits, second half of bits
        b64 = (int32)buf;
        b32 = (int32)(buf >> 32);

        AddBuf(b64);
        AddBuf(b32);
    }
    void JCS_Buffer::AddBuf(uint64 buf)
    {
        AddBuf((int64)buf);
    }
    void JCS_Buffer::AddBuf(float64 buf)
    {
        // Assign data
        JCS_FLOAT64 data(buf);

        // put the float64 into single byte
        byte b1, b2, b3, b4, b5, b6, b7, b8;
        b1 = data.buffer.bytes[0];
        b2 = data.buffer.bytes[1];
        b3 = data.buffer.bytes[2];
        b4 = data.buffer.bytes[3];
        b5 = data.buffer.bytes[4];
        b6 = data.buffer.bytes[5];
        b7 = data.buffer.bytes[6];
        b8 = data.buffer.bytes[7];

        // add byte into the buffer array! (this builder)
        AddBuffer(b1, sizeof(float32));
        AddBuffer(b2, sizeof(float32));
        AddBuffer(b3, sizeof(float32));
        AddBuffer(b4, sizeof(float32));
        AddBuffer(b5, sizeof(float32));
        AddBuffer(b6, sizeof(float32));
        AddBuffer(b7, sizeof(float32));
        AddBuffer(b8, sizeof(float32));
    }


}

