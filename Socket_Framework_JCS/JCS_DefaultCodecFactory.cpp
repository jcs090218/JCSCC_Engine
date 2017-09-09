/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*               Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

/**
 * $File: JCS_DefaultCodecFactory.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JCS_DefaultCodecFactory.h"


#include "JCS_DefaultPacketDecoder.h"
#include "JCS_DefaultPacketEncoder.h"

namespace JCS_Network
{

    JCS_DefaultCodecFactory* JCS_DefaultCodecFactory::s_pCodecFactory = nullptr;

    JCS_DefaultCodecFactory::JCS_DefaultCodecFactory()
            : m_pDecoder(nullptr)
            , m_pEncoder(nullptr)
    {
        m_pDecoder = new JCS_DefaultPacketDecoder();
        m_pEncoder = new JCS_DefaultPacketEncoder();
    }

    JCS_DefaultCodecFactory::~JCS_DefaultCodecFactory()
    {
        SafeDeleteObject(m_pDecoder);
        SafeDeleteObject(m_pEncoder);
    }

}
