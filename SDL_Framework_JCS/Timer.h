#ifndef __TIMER_H__
#define __TIMER_H__

#include "SDL_StdAfx.h"

namespace JCS_SDL_Engine
{
    class Timer
    {
    private:
        //The clock time when the timer started
        Uint32 m_startTicks;

        //The ticks stored when the timer was paused
        Uint32 m_pausedTicks;

        //The timer status
        bool m_paused;
        bool m_started;

    public:
        //Initializes variables
        Timer();
        virtual ~Timer();

        //The various clock actions
        void Start();
        void Stop();
        void Pause();
        void Unpause();

        //Gets the timer's time
        Uint32 GetTicks();

        //Checks the status of the timer
        bool is_started() const { return this->m_started; }
        bool is_paused() const { return this->m_paused; }
    };

}

#endif // __TIMER_H__

