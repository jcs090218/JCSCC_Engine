#ifndef __JCSKEY_H__
#define __JCSKEY_H__


#include "JcsLib_StdAfx.h"

namespace JcsLib
{
    struct JcsKey
    {
        static const uint32 jcs_key_file_v01_num = 65535;
        static const uint32 jcs_key_file_v02_num = 26076;

        // Keys
        static byte jcs_key_file_v01[jcs_key_file_v01_num];
        static byte jcs_key_file_v02[jcs_key_file_v02_num];

    };

    
}

#endif // __JCSKEY_H__

