#ifndef __JCS_BINARYREADER_H__
#define __JCS_BINARYREADER_H__


#include "JayCeS_StdAfx.h"
#include "JCS_BufferBuilder.h"

namespace JayCeS
{
    class IJcsObject;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_BinaryReader
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_BinaryReader
    {
    private:
        size_t m_length;
        byte* m_buffer = nullptr;
        FILE* m_file = nullptr;
        JCS_BufferBuilder* m_pJcsBufferBuilder;

    public:
        JCS_BinaryReader();
        ~JCS_BinaryReader();

        // Cross OS
        size_t GetFileSize(const wchar_t* filename);
        size_t GetFileSize(const char* filename);

        // Windows SDK
#ifdef _WIN32
#ifdef _UNICODE
        /**
            Tutorial & Information: 
                * C++ BINARY FILE I/O (Youtube Video)
                https://www.youtube.com/watch?v=P5_ED_JuGls
                * Get rid of "_CRT_SECURE_NO_WARNINGS"
                http://stackoverflow.com/questions/21873048/getting-an-error-fopen-this-function-or-variable-may-be-unsafe-when-complin
                * MSDN (fopen_s、_wfopen_s):
                https://msdn.microsoft.com/zh-tw/library/z5hh6ee9.aspx
        */
        void Read(const wchar_t* filePath, IJcsObject* dataStruct);
        byte* Read(const wchar_t* filePath);
#else
        /* Information at "_UNICODE" section */
        void Read(const char* filePath, IJcsObject* dataStruct);
        byte* Read(const char* filePath);
#endif
#endif // _WIN32

        void ClearFile();
        void ClearBuffer();

        void PeekBuffer() const { GetJBufferBuilderPtr()->PeekBuffer(); }

        /* Read the buffer then delete the "chunk of 
            buffer" from the buffer*/
        byte ReadByte8();
        char ReadChar8();
        int16 ReadShort16();
        uint16 ReadUShort16();
        int32 ReadInt32();
        uint32 ReadUInt32();
        int64 ReadInt64();
        uint64 ReadUInt64();
        float32 ReadFloat32();
        float64 ReadFloat64();

        // setter

        // getter
        size_t GetLength() const { return this->m_length; }
        FILE* GetFile() const { return this->m_file; }
        JCS_BufferBuilder* GetJBufferBuilderPtr() const { return this->m_pJcsBufferBuilder; }
        JCS_BufferBuilder& GetJBufferBuilderRef() const { return *(this->m_pJcsBufferBuilder); }

    private:
        bool CheckBufferLength(size_t lenToCheck);
        bool CheckBuffer();

        // setter
        void SetLength(const size_t len) { this->m_length = len; }
    };

}

typedef JayCeS::JCS_BinaryReader JCS_BinaryReader;

#endif // __JCS_BINARYREADER_H__

