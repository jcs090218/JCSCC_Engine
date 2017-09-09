/*******************************************************************
 *                   JCSCC_Framework Version 0.2.7
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   See LICENSE.txt for modification and distribution information
 *               Copyright (c) 2016 by Shen, Jen-Chieh
 ******************************************************************/

#ifndef __JCS_DEFAULTPACKETENCODER_H__
/**
 * $File: JCS_DefaultPacketEncoder.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_DEFAULTPACKETENCODER_H__

#include "Socket_StdAfx.h"

namespace JCS_Network
{

    //====================================================================================
    // Class Name : JCS_DefaultPacketEncoder 
    //
    // Description : Writer object encode/encrypt the packet 
    //       from the server.
    //====================================================================================
    class JCS_DefaultPacketEncoder
        : public JCS_PacketEncoder
    {
    public:
        JCS_DefaultPacketEncoder();
        ~JCS_DefaultPacketEncoder();

        /**
            Encode/Encrypt the object message into packet format.
        */
        virtual void Encode() override;

    };
}

#endif // __JCS_DEFAULTPACKETENCODER_H__
