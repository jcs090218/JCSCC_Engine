/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "TimeManager.h"


namespace JCS_GameTool
{
    TimeManager* TimeManager::s_pTimeManager = nullptr;

    TimeManager::TimeManager()
    {

    }

    TimeManager::~TimeManager()
    {
        s_pTimeManager = nullptr;
    }

}

