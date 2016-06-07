/*******************************************************************
 *                   JCSCC_Framework Version 1.0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   See LICENSE.txt for modification and distribution information
 *               Copyright (c) 2016 by Shen, Jen-Chieh
 ******************************************************************/

#ifndef __JCS_DEFAULTPACKETENCODER_H__
#define __JCS_DEFAULTPACKETENCODER_H__

#include "Socket_StdAfx.h"

namespace JCS_Network
{

    //------------------------------------------------------------------------------------
    // Name : JCS_DefaultPacketEncoder 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JCS_DefaultPacketEncoder
        : public JCS_PacketEncoder
    {
    public:
        JCS_DefaultPacketEncoder();
        ~JCS_DefaultPacketEncoder();

        virtual void Encode() override;

    };
}

#endif // __JCS_DEFAULTPACKETENCODER_H__
