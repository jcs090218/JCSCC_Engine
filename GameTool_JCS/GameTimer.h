#ifndef __GAMETIMER_H__
#define __GAMETIMER_H__

namespace JCS_GameTool
{
	class GameTimer
	{
    private:
        double mSecondsPerCount;
        double mDeltaTime;

        __int64 mBaseTime;
        __int64 mPausedTime;
        __int64 mStopTime;
        __int64 mPrevTime;
        __int64 mCurrTime;

        bool mStopped;

	public:
		GameTimer();

		float TotalTime()const;  // in seconds
		float DeltaTime()const; // in seconds

		void Reset(); // Call before message loop.
		void Start(); // Call when unpaused.
		void Stop();  // Call when paused.
		void Tick();  // Call every frame.

	};

}

typedef JCS_GameTool::GameTimer GameTimer;

#endif // __GAMETIMER_H__

