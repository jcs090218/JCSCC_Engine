#ifndef __SDL_MIXER_MUSIC_H__
#define __SDL_MIXER_MUSIC_H__


#include <SDL_Framework_JCS\SDL_StdAfx.h>

namespace JCS_GameSound
{

    //------------------------------------------------------------------------------------
    // Name : SDL_Mixer_Music 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class SDL_Mixer_Music
    {
    private:
        friend class SDL_Mixer_AudioEngine;

        Mix_Music* m_music = nullptr;
    public:
        // Plays the music file
        // @param loops: If loops == -1, loop forever,
        // otherwise play it loops times
        void play(int32 loops = -1);

        void pause();
        void stop();
        void resume();
    };
}

typedef JCS_GameSound::SDL_Mixer_Music SDL_Mixer_Music;

#endif // __SDL_MIXER_MUSIC_H__

