/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

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

