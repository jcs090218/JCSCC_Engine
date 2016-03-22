#ifndef __JCS_SOUNDAPI_H__
#define __JCS_SOUNDAPI_H__



namespace JCS_GameSound
{

    //------------------------------------------------------------------------------------
    // Name : SoundAPI (enum) 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    enum class SoundAPI
    {
#ifdef _WIN32
        DIRECT_SOUND,
        DIRECT_MUSIC,
        DIRECT_SHOW,
#endif // WIN32
        FMOD,
        SDL_MIXER,
        XAUDIO2
    };

}

#endif // __JCS_SOUNDAPI_H__

