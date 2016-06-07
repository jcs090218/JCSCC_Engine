/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_PACETENCODER_H__
#define __JCS_PACETENCODER_H__


namespace JCS_Network
{

    //------------------------------------------------------------------------------------
    // Name : JCS_PacketEncoder 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
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
