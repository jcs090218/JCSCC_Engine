/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*               Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_DEFAULTPACKETDECODER_H__
#define __JCS_DEFAULTPACKETDECODER_H__

#include "Socket_StdAfx.h"

namespace JCS_Network
{

    //------------------------------------------------------------------------------------
    // Name : JCS_DefaultPacketDecoder 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JCS_DefaultPacketDecoder
        : public JCS_PacketDecoder
    {
    public:
        JCS_DefaultPacketDecoder();
        ~JCS_DefaultPacketDecoder();

        virtual void Decode() override;

    };
}

#endif // __JCS_DEFAULTPACKETDECODER_H__
