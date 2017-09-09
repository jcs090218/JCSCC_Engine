/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*               Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_DEFAULTPACKETDECODER_H__
/**
 * $File: JCS_DefaultPacketDecoder.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_DEFAULTPACKETDECODER_H__

#include "Socket_StdAfx.h"

namespace JCS_Network
{

    //====================================================================================
    // Class Name : JCS_DefaultPacketDecoder 
    //
    // Description : Writer object to decode/decrypt the packet 
    //       from the server.
    //====================================================================================
    class JCS_DefaultPacketDecoder
        : public JCS_PacketDecoder
    {
    public:
        JCS_DefaultPacketDecoder();
        ~JCS_DefaultPacketDecoder();

        /**
            Decode/Dencrypt the packet into object message.
        */
        virtual void Decode() override;

    };
}

#endif // __JCS_DEFAULTPACKETDECODER_H__
