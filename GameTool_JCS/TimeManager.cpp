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

