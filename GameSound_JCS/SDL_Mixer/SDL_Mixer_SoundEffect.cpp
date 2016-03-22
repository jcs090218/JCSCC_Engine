#include "SDL_Mixer_SoundEffect.h"


namespace JCS_GameSound
{
    void SDL_Mixer_SoundEffect::play(int loops /*= 0*/)
    {
        if (Mix_PlayChannel(-1, m_chunck, loops) == -1) 
        {
            if (Mix_PlayChannel(0, m_chunck, loops) == -1) 
            {
                JCS_SDL_Engine::fatalError("Mix_Init error: " + std::string(Mix_GetError()));
            }
        }
    }

}

