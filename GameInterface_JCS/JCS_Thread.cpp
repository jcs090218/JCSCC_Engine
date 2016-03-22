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

