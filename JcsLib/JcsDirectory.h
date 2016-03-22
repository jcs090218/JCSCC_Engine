#ifndef __JCS_DIRECTORY_H__
#define __JCS_DIRECTORY_H__


#include "IJcsObject.h"
#include "JcsImage.h"

namespace JcsLib
{
    class JcsDirectory
    {
    private:
        uint32 m_blockStartOffset;
        int32 m_checksum;
        int32 m_hash;
        uint32 m_headerOffsetOffset;
        std::list<JcsImage> m_images;
        std::string m_name;
        uint32 m_offset;
        int32 m_offsetSize;
        IJcsObject m_parent;
        std::list<JcsDirectory> m_subDirs;
        //BinaryReader m_jcsReader;

    public:
        JcsDirectory();
        ~JcsDirectory();

    };

}

#endif // __JCS_DIRECTORY_H__

