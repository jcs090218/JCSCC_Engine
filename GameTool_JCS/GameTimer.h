#ifndef __GAMETIMER_H__
/**
 * $File: GameTimer.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __GAMETIMER_H__


namespace JCS_GameTool
{

	//====================================================================================
	// Name : GameTimer 
	//
	// Description : 
	//====================================================================================
    class GameTimer
    {
    private:
        double m_secondsPerCount;
        double m_deltaTime;

        __int64 m_baseTime;
        __int64 m_pausedTime;
        __int64 m_stopTime;
        __int64 m_prevTime;
        __int64 m_currTime;

        bool m_stopped;

    public:
        GameTimer();

        float TotalTime() const;  // in seconds
        float DeltaTime() const; // in seconds

        void Reset(); // Call before message loop.
        void Start(); // Call when unpaused.
        void Stop();  // Call when paused.
        void Tick();  // Call every frame.

    };

}

typedef JCS_GameTool::GameTimer GameTimer;

#endif // __GAMETIMER_H__

