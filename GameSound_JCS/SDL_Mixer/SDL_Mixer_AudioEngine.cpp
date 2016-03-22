#include "SDL_Mixer_AudioEngine.h"


namespace JCS_GameSound
{
    SDL_Mixer_AudioEngine::SDL_Mixer_AudioEngine()
    {

    }

    SDL_Mixer_AudioEngine::~SDL_Mixer_AudioEngine()
    {
        Destroy();
    }

    void SDL_Mixer_AudioEngine::Initialize()
    {
        // do not want to initialize twice or more...
        if (m_isInitialized)
            return;

        // Parameter can be a bitwase combination of MIX_INIT_FAC,
        // MIX_INIT_MOD, MIX_INIT_MP3, MIX_INIT_OGG
        if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1)
            JCS_SDL_Engine::fatalError("Mix_Init error: " + std::string(Mix_GetError()));

        if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
            JCS_SDL_Engine::fatalError("Mix_Init error: " + std::string(Mix_GetError()));

        // Success initialized
        m_isInitialized = true;
    }

    void SDL_Mixer_AudioEngine::Destroy()
    {
        if (m_isInitialized)
        {
            for (auto& it : m_effectMap)
                Mix_FreeChunk(it.second);

            for (auto& it : m_musicMap)
                Mix_FreeMusic(it.second);

            m_effectMap.clear();
            m_musicMap.clear();
            Mix_Quit();

            m_isInitialized = false;
        }
    }

    SDL_Mixer_SoundEffect SDL_Mixer_AudioEngine::LoadSoundEffect(const std::string& filePath)
    {
        // Try to find the audio in the cache
        auto it = m_effectMap.find(filePath);

        SDL_Mixer_SoundEffect effect;

        if (it == m_effectMap.end()) {
            // Failed to find it, must load
            Mix_Chunk* chunk = Mix_LoadWAV(filePath.c_str());

            if (chunk == nullptr)
                JCS_SDL_Engine::fatalError("Mix_Init error: " + std::string(Mix_GetError()));

            effect.m_chunck = chunk;
            m_effectMap[filePath] = chunk;
        }
        else {
            // Its already cached
            effect.m_chunck = it->second;
        }

        return effect;
    }

    SDL_Mixer_Music SDL_Mixer_AudioEngine::LoadMusic(const std::string& filePath)
    {
        // Try to find the audio in the cache
        auto it = m_musicMap.find(filePath);

        SDL_Mixer_Music music;

        if (it == m_musicMap.end()) {
            // Failed to find it, must load
            Mix_Music* mixMusic = Mix_LoadMUS(filePath.c_str());

            if (mixMusic == nullptr)
                JCS_SDL_Engine::fatalError("Mix_Init error: " + std::string(Mix_GetError()));

            music.m_music = mixMusic;
            m_musicMap[filePath] = mixMusic;
        }
        else {
            // Its already cached
            music.m_music = it->second;
        }

        return music;
    }

}

