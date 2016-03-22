#ifndef __SDL_MIXER_AUDIOENGINE_H__
#define __SDL_MIXER_AUDIOENGINE_H__

#include "..\GameSound_StdAfx.h"

#include <SDL_Framework_JCS\SDL_StdAfx.h>

#include "SDL_Mixer_SoundEffect.h"
#include "SDL_Mixer_Music.h"

namespace JCS_GameSound
{

    //------------------------------------------------------------------------------------
    // Name : SDL_Mixer_AudioEngine 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class SDL_Mixer_AudioEngine
    {
    private:
        bool m_isInitialized = false;
        std::map<std::string, Mix_Chunk*> m_effectMap;      /// Effect cache
        std::map<std::string, Mix_Music*> m_musicMap;       /// Music cache

    public:
        SDL_Mixer_AudioEngine();
        ~SDL_Mixer_AudioEngine();

        void Initialize();
        void Destroy();

        SDL_Mixer_SoundEffect LoadSoundEffect(const std::string& filePath);
        SDL_Mixer_Music LoadMusic(const std::string& filePath);
    };

}

typedef JCS_GameSound::SDL_Mixer_AudioEngine SDL_Mixer_AudioEngine;

#endif // __SDL_MIXER_AUDIOENGINE_H__

