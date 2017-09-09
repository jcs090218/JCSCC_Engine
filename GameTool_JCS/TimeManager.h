#ifndef __TIMEMANAGER_H__
/**
 * $File: TimeManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __TIMEMANAGER_H__

#include "GameTool_StdAfx.h"

namespace JCS_GameTool
{

    //====================================================================================
    // Class Name : TimeManager 
    //
    // Description : Manager manage all the time in the application.
    // Especially the time between the packet receive (OS/Networl Layer).
    // Once it receive the packet we manage to check logger and manage
    // the packet correction between the client and server.
    //====================================================================================
    class TimeManager
		: public JCSSTL::JCSSTL_Singleton<TimeManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<TimeManager>;

    public:

        virtual ~TimeManager();



        /** setter **/

        /** getter **/

	private:
		// Constructor
		TimeManager();
		TimeManager(const TimeManager& right) = delete;

    };
}

typedef JCS_GameTool::TimeManager TimeManager;

#endif // __TIMEMANAGER_H__

