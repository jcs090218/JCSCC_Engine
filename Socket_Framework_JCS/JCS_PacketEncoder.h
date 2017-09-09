/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_PACETENCODER_H__
/**
 * $File: JCS_PacketEncoder.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_PACETENCODER_H__


namespace JCS_Network
{

    //====================================================================================
    // Class Name : JCS_PacketEncoder 
    //
    // Description : Interface for Encoder.
    //====================================================================================
    class JCS_PacketEncoder
    {
    public:
        virtual ~JCS_PacketEncoder() { }

        // TODO(JenChieh): Encode should return something and 
        //              pass in the byte array(message)
        virtual void Encode() = 0;
    };
}

typedef JCS_Network::JCS_PacketEncoder JCS_PacketEncoder;

#endif // __JCS_PACETENCODER_H__
