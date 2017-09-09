/**
 * $File: GameTimer.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include <windows.h>
#include "GameTimer.h"


namespace JCS_GameTool
{

    GameTimer::GameTimer()
        : m_secondsPerCount(0.0)
        , m_deltaTime(-1.0)
        , m_baseTime(0)
        , m_pausedTime(0)
        , m_prevTime(0)
        , m_currTime(0)
        , m_stopped(false)
    {
        __int64 countsPerSec;
        QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
		m_secondsPerCount = 1.0 / (double)countsPerSec;
    }

    // Returns the total time elapsed since Reset() was called, NOT counting any
    // time when the clock is stopped.
    float GameTimer::TotalTime() const
    {
        // If we are stopped, do not count the time that has passed since we stopped.
        // Moreover, if we previously already had a pause, the distance 
        // m_stopTime - mBaseTime includes paused time, which we do not want to count.
        // To correct this, we can subtract the paused time from m_stopTime:  
        //
        //                     |<--paused time-->|
        // ----*---------------*-----------------*------------*------------*------> time
        //  mBaseTime       m_stopTime        startTime     m_stopTime    m_currTime

        if (m_stopped)
        {
            return (float)(((m_stopTime - m_pausedTime) - m_baseTime) * m_secondsPerCount);
        }

        // The distance m_currTime - mBaseTime includes paused time,
        // which we do not want to count.  To correct this, we can subtract 
        // the paused time from m_currTime:  
        //
        //  (m_currTime - m_pausedTime) - mBaseTime 
        //
        //                     |<--paused time-->|
        // ----*---------------*-----------------*------------*------> time
        //  mBaseTime       m_stopTime        startTime     m_currTime

        else
        {
            return (float)(((m_currTime - m_pausedTime) - m_baseTime) * m_secondsPerCount);
        }
    }

    float GameTimer::DeltaTime() const
    {
        return static_cast<float>(m_deltaTime);
    }

    void GameTimer::Reset()
    {
        __int64 currTime;
        QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

        m_baseTime = currTime;
        m_prevTime = currTime;
        m_stopTime = 0;
        m_stopped = false;
    }

    void GameTimer::Start()
    {
        __int64 startTime;
        QueryPerformanceCounter((LARGE_INTEGER*)&startTime);


        // Accumulate the time elapsed between stop and start pairs.
        //
        //                     |<-------d------->|
        // ----*---------------*-----------------*------------> time
        //  mBaseTime       m_stopTime        startTime     

        if (m_stopped)
        {
            m_pausedTime += (startTime - m_stopTime);

            m_prevTime = startTime;
            m_stopTime = 0;
            m_stopped = false;
        }
    }

    void GameTimer::Stop()
    {
        if (!m_stopped)
        {
            __int64 currTime;
            QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

            m_stopTime = currTime;
            m_stopped = true;
        }
    }

    void GameTimer::Tick()
    {
        if (m_stopped)
        {
			m_deltaTime = 0.0;
            return;
        }

        __int64 currTime;
        QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
        m_currTime = currTime;

        // Time difference between this frame and the previous.
		m_deltaTime = (m_currTime - m_prevTime) * m_secondsPerCount;

        // Prepare for next frame.
        m_prevTime = m_currTime;

        // Force nonnegative.  The DXSDK's CDXUTTimer mentions that if the 
        // processor goes into a power save mode or we get shuffled to another
        // processor, then mDeltaTime can be negative.
        if (m_deltaTime < 0.0)
        {
			m_deltaTime = 0.0;
        }
    }

}

