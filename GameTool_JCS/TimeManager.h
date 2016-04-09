/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __TIMEMANAGER_H__
#define __TIMEMANAGER_H__


namespace JCS_GameTool
{

    //------------------------------------------------------------------------------------
    // Name : TimeManager 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class TimeManager
    {
    private:
        static TimeManager* s_pTimeManager;
        TimeManager();

    public:
        static TimeManager* getInstance()
        {
            if (!s_pTimeManager)
                s_pTimeManager = new TimeManager;
            return s_pTimeManager;
        }
        virtual ~TimeManager();



        // setter

        // getter

    };
}

typedef JCS_GameTool::TimeManager TimeManager;

#endif // __TIMEMANAGER_H__

