#ifndef __SDL_MIXER_SOUNDEFFECT_H__
#define __SDL_MIXER_SOUNDEFFECT_H__


#include <SDL_Framework_JCS\SDL_StdAfx.h>

namespace JCS_GameSound
{

    //====================================================================================
    // Name : SDL_Mixer_SoundEffect 
    //
    // Description : 
    //====================================================================================
    class SDL_Mixer_SoundEffect
    {
    private:
        friend class SDL_Mixer_AudioEngine;

        Mix_Chunk* m_chunck = nullptr;

    public:
        // Plays the effect file
        // @param loops: If loops == 0, loop forever,
        // otherwise play it loops times
        void play(int32 loops = 0);
    };

}

typedef JCS_GameSound::SDL_Mixer_SoundEffect SDL_Mixer_SoundEffect;

#endif // __SDL_MIXER_SOUNDEFFECT_H__

