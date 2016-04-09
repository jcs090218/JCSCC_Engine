/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_THREAD_H__
#define __JCS_THREAD_H__

#include "GameInterface_StdAfx.h"

namespace JCS_GameInterface
{
    class JCS_Thread
    {
    private:
        std::thread m_thread;

    public:
        explicit JCS_Thread();
        virtual ~JCS_Thread();

        // setter

        // getter

    };
}

typedef JCS_GameInterface::JCS_Thread JCS_Thread;

#endif // __JCS_THREAD_H__

