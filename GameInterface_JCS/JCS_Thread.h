#ifndef __JCS_THREAD_H__
/**
* $File: JCS_Thread.h $
* $Date: $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2015 by Shen, Jen-Chieh $
*/
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

        /** setter **/

        /** getter **/

    };
}

typedef JCS_GameInterface::JCS_Thread JCS_Thread;

#endif // __JCS_THREAD_H__

