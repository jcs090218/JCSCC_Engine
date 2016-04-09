/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JCS_Thread.h"


namespace JCS_GameInterface
{
    JCS_Thread::JCS_Thread()
        : m_thread()
    {

    }

    JCS_Thread::~JCS_Thread()
    {
        if (m_thread.joinable())
            m_thread.join();
    }

}

