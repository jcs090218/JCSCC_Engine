#include "SDL_Mixer_Music.h"


namespace JCS_GameSound
{
    void SDL_Mixer_Music::play(int loops /*= -1*/)
    {
        Mix_PlayMusic(m_music, loops);
    }

    void SDL_Mixer_Music::pause()
    {
        Mix_PauseMusic();
    }

    void SDL_Mixer_Music::stop()
    {
        Mix_HaltMusic();
    }

    void SDL_Mixer_Music::resume()
    {
        Mix_ResumeMusic();
    }

}

