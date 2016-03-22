#ifndef __JCS_BUFFER_H__
#define __JCS_BUFFER_H__


#include "JayCeS_StdAfx.h"

namespace JayCeS
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_Buffer
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_Buffer
    {
    private:
        std::queue<byte> m_buffer;

    public:
        JCS_Buffer();
        ~JCS_Buffer();

        void AddBuffer(byte buf, const size_t len);
        void AddBuf(byte buf);
        void AddBuf(char buf);
        void AddBuf(int16 buf);
        void AddBuf(uint16 buf);
        void AddBuf(int32 buf);
        void AddBuf(uint32 buf);
        void AddBuf(float32 buf);
        void AddBuf(int64 buf);
        void AddBuf(uint64 buf);
        void AddBuf(float64 buf);

        byte RemoveBuffer();

        void ClearBuffer();

        // setter

        // getter
        std::queue<byte>& GetBuffer() { return this->m_buffer; }
        size_t GetLength() const { return this->m_buffer.size(); }

    };

}

typedef JayCeS::JCS_Buffer JCS_Buffer;

#endif // __JCS_BUFFER_H__

