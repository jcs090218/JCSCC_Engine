/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_SOUNDAPI_H__
/**
 * $File: SoundAPI.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_SOUNDAPI_H__


namespace JCS_GameSound
{

    //====================================================================================
    // Name : SoundAPI (enum) 
    //
    // Description : 
    //====================================================================================
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

