#ifndef __SOUNE_H__
#define __SOUNE_H__

#include "..\GameSound_StdAfx.h"

#include "Wavread.h"

namespace JCS_GameSound
{
    class Sound
    {
    private:
        CWaveSoundRead* m_pWaveSoundRead;
        LPDIRECTSOUNDBUFFER8 m_pBuffer;
        int m_bufferSize;

        /**
        * Multiple sounds that use the same
        * file shouldn't re-read it, they should
        * share the CWSR object.  This map
        * implements rudimentary reference counting.
        * I would have just changed CWaveSoundRead,
        * but I wanted to keep it unchanged from the
        * samples.
        */
        static std::map< CWaveSoundRead*, int > m_waveMap;

        void Init();

    public:
        Sound(TCHAR* filename);
        Sound(Sound& in);

        Sound& operator=(const Sound &in);

        ~Sound();
        void Restore();
        void Fill();
        void Play(bool bLoop = false);

        bool IsPlaying();
    };

}

typedef JCS_GameSound::Sound Sound;

#endif //__SOUNE_H__

