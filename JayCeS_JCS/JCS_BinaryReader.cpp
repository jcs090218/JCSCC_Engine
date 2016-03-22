#include "JCS_BinaryReader.h"


#include <JcsLib\IJcsObject.h>

namespace JayCeS
{

    JCS_BinaryReader::JCS_BinaryReader()
    {
        m_pJcsBufferBuilder = new JCS_BufferBuilder();
    }

    JCS_BinaryReader::~JCS_BinaryReader()
    {
        ClearBuffer();
        ClearFile();
        SafeDeleteObject(m_pJcsBufferBuilder);
    }

    // Cross OS
    size_t JCS_BinaryReader::GetFileSize(const wchar_t* filename)
    {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return (size_t)in.tellg();
    }
    size_t JCS_BinaryReader::GetFileSize(const char* filename)
    {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return (size_t)in.tellg();
    }
    
    // Windows SDK
#ifdef _WIN32
#ifdef _UNICODE
    void JCS_BinaryReader::Read(const wchar_t* filePath, IJcsObject* dataStruct)
    {
        // Clear File before reuse.
        ClearFile();

        // Open a file with "rb" (READ BINARY)
        m_file = _wfopen(filePath, L"rb");

        // Read Binary File
        m_length = sizeof(dataStruct);
        fread(&dataStruct, m_length, 1, m_file);
    }
    byte* JCS_BinaryReader::Read(const wchar_t* filePath)
    {
        // Clear Buffer and File before reuse.
        ClearBuffer();
        ClearFile();

        // After clear 
        m_pJcsBufferBuilder->GetJcsBuffer()->ClearBuffer();

        // Get the file size and allocate the memory to the 
        // exact size.
        m_length = GetFileSize(filePath);
        m_buffer = (byte*)malloc(m_length);

        // open the file and read the file into buffer.
        m_file = _wfopen(filePath, L"rb");
        fread(m_buffer, m_length, 1, m_file);

        // Assign Buffer
        JCS_Buffer* jcsBuf = GetJBufferBuilderPtr()->GetJcsBuffer();
        for (size_t buffCount = 0; buffCount < m_length; ++buffCount)
            jcsBuf->AddBuffer(m_buffer[buffCount], m_length);

        // return buffer in order to use the data.
        return m_buffer;
    }

#else
    void JCS_BinaryReader::Read(const char* filePath, IJcsObject* dataStruct)
    {
        // Clean the file before reuse.
        ClearFile();

        // Open a file with "rb" (READ BINARY)
        m_file = fopen(filePath, "rb");

        // Read Binary File
        m_length = sizeof(dataStruct);
        fread(&dataStruct, sizeof(dataStruct), 1, m_file);
    }
    byte* JCS_BinaryReader::Read(const char* filePath)
    {
        // Clear Buffer and File before reuse.
        ClearBuffer();
        ClearFile();

        // Get the file size and allocate the memory to the 
        // exact size.
        m_length = GetFileSize(filePath);
        m_buffer = (byte*)malloc(m_length);

        // open the file and read the file into buffer.
        m_file = fopen(filePath, L"rb");
        fread(m_buffer, m_length, 1, m_file);

        // return buffer in order to use the data.
        return m_buffer;
    }
#endif
#endif // _WIN32

    void JCS_BinaryReader::ClearFile()
    {
        if (m_file)
            fclose(m_file);
    }
    void JCS_BinaryReader::ClearBuffer()
    {
        SafeFreeObject(m_buffer);
    }

    // Functional Function
    byte JCS_BinaryReader::ReadByte8()
    {
        return GetJBufferBuilderPtr()->ReadByte8();
    }
    char JCS_BinaryReader::ReadChar8()
    {
        return static_cast<char>(ReadByte8());
    }
    int16 JCS_BinaryReader::ReadShort16()
    {
        return GetJBufferBuilderPtr()->ReadShort16();
    }
    uint16 JCS_BinaryReader::ReadUShort16()
    {
        return (uint16)(GetJBufferBuilderPtr()->ReadShort16());
    }
    int32 JCS_BinaryReader::ReadInt32()
    {
        return GetJBufferBuilderPtr()->ReadInt32();
    }
    uint32 JCS_BinaryReader::ReadUInt32()
    {
        return (uint32)(GetJBufferBuilderPtr()->ReadInt32());
    }
    int64 JCS_BinaryReader::ReadInt64()
    {
        return GetJBufferBuilderPtr()->ReadInt64();
    }
    uint64 JCS_BinaryReader::ReadUInt64()
    {
        return (uint64)(GetJBufferBuilderPtr()->ReadInt64());
    }
    float32 JCS_BinaryReader::ReadFloat32()
    {
        return GetJBufferBuilderPtr()->ReadFloat32();
    }
    float64 JCS_BinaryReader::ReadFloat64()
    {
        return GetJBufferBuilderPtr()->ReadFloat64();
    }

    // Support
    bool JCS_BinaryReader::CheckBufferLength(size_t lenToCheck)
    {
        // File do not have enough data in the buffer.
        if (GetLength() < lenToCheck)
            return false;

        // buffer avaliable
        return true;
    }
    bool JCS_BinaryReader::CheckBuffer()
    {
        if (!m_buffer)
        {
            throw JCS_Error(L"Buffer are not avaliable yet...");
            return false;
        }

        return true;
    }

}

