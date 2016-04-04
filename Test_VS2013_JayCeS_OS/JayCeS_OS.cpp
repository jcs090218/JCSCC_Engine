#include "JayCeS_OS.h"



#include <JayCeS_JCS\JayCeS.h>
#include <JcsLib\JcsLib.h>

using namespace std;

JayCeS_OS::JayCeS_OS()
{

}

JayCeS_OS::~JayCeS_OS()
{

}

static byte g_arrat[2] = { 1, 2 };

void JayCeS_OS::Run()
{
    SetConsoleOutputCP(CP_UTF8);

    JCS_BufferBuilder buffer;

    byte data = 'a';
    buffer.WriteByte8(data);
    data = 'b';
    buffer.WriteByte8(data);
    data = 'c';
    buffer.WriteByte8(data);

    short shortData = 260;
    buffer.WriteShort16(shortData);

    int intData = 1035450416;
    buffer.WriteInt32(intData);

    float fData = 23.2f;
    buffer.WriteFloat32(fData);

    unsigned long long uint64Data = 999999999;
    buffer.WriteInt64(uint64Data);

    data = 'd';
    buffer.WriteByte8(data);
    data = 'e';
    buffer.WriteByte8(data);


    buffer.ReadByte8();     // a
    buffer.ReadByte8();     // b
    buffer.ReadByte8();     // c

    cout << buffer.ReadShort16() << endl;     // 260
    cout << buffer.ReadInt32() << endl;     // 1035450416
    cout << buffer.ReadFloat32() << endl;   // 23.2
    cout << buffer.ReadUInt64() << endl;   // 999999999
   
    buffer.PeekBuffer();

    cout << "-------------------------------------------------------" << endl;

    //-- Binary Reader Test
    {
        JCS_BinaryReader* reader = new JCS_BinaryReader;
        reader->Read(L"C:/Users/JenChieh/Downloads/Base.jcs");

        for (int i = 0; i < 4; ++i)
            reader->ReadByte8();

        unsigned long long x_size = 0;
        unsigned int f_start = 0;
        wchar_t* f_copyright = L"";
        unsigned short f_version = 0;

        // Get information
        x_size = reader->ReadUInt64();
        f_start = reader->ReadUInt32();
        f_copyright = JcsTools::ReadNullTerminatedString(*reader);
        f_version = reader->ReadShort16();

        // Print information
        {
            cout << "File Size: " << x_size << endl;
            cout << "File Size 2: " << reader->GetLength() << endl;
            cout << "File Start: " << f_start << endl;
            wcout << L"Copy Right: " << f_copyright << endl;
            cout << "Version: " << f_version << endl;
        }

        // See the Stream
        reader->PeekBuffer();

        SafeDeleteObject(reader);
    }

    cout << "-------------------------------------------------------" << endl;

    //-- Test String
    {
        /*JCS_StringBuilder builder;

        builder.Append('C');
        builder.Append('o');
        builder.Append('p');
        builder.Append('y');

        wchar_t* copy = builder.ToString();
        wcout << L"Version: " << copy << endl;*/
    }


    // TODO(JenChieh): Try to print out the unicode. (Chinese)
    printf("\n你好!");
}

