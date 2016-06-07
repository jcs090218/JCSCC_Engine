/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*               Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_DEFAULTCODECFACTORY_H__
#define __JCS_DEFAULTCODECFACTORY_H__


#include "Socket_StdAfx.h"


namespace JCS_Network
{

    class JCS_DefaultCodecFactory
        : public JCS_CodecFactory
    {
    private:
        static JCS_DefaultCodecFactory* s_pCodecFactory;

        JCS_PacketDecoder* m_pDecoder;
        JCS_PacketEncoder* m_pEncoder;

        JCS_DefaultCodecFactory();

    public:
        virtual ~JCS_DefaultCodecFactory();

        static JCS_DefaultCodecFactory* GetInstance()
        {
            if (!s_pCodecFactory)
                s_pCodecFactory = new JCS_DefaultCodecFactory();
            
            return s_pCodecFactory;
        }

        JCS_PacketDecoder* GetDecoder() const { return this->m_pDecoder; }
        JCS_PacketEncoder* GetEncoder() const { return this->m_pEncoder; }

    };
}

#endif // __JCS_CODECFACTORY_H__
