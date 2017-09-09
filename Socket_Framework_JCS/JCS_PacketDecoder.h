/*******************************************************************
 *                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_PACETDECODER_H__
/**
 * $File: JCS_PacketDecoder.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_PACETDECODER_H__


namespace JCS_Network
{

    //====================================================================================
    // Class Name : JCS_PacketDecoder 
    // 
    // Description : Interface for Decoder. 
    //====================================================================================
    class JCS_PacketDecoder
    {
    public:
        virtual ~JCS_PacketDecoder() { }

        // TODO(JenChieh): Decode should return something and 
        //              pass in the byte array(message)
        virtual void Decode() = 0;
    };
}

typedef JCS_Network::JCS_PacketDecoder JCS_PacketDecoder;

#endif // __JCS_PACETDECODER_H__
