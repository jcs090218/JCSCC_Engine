/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*               Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_CODECFACTORY_H__
/**
 * $File: JCS_CodecFactory.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_CODECFACTORY_H__


namespace JCS_Network
{

    //====================================================================================
    // Name : JCS_CodecFactory 
    //
    // Description : Interface for Packet Encoder and Decoder.
    //====================================================================================
    class JCS_CodecFactory
    {
    public:
        virtual ~JCS_CodecFactory() { }
    };

}

#endif // __JCS_CODECFACTORY_H__
