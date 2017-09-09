#ifndef __SDL_NET_SOCKET_H__
/**
 * $File: SDLNet_Socket.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __SDL_NET_SOCKET_H__


#include "Socket_StdAfx.h"

namespace JCS_Network
{

    /**
     * @class SDLNet_Socket
     * @brief Socket Layer using Simple DirectMedia Layer. (Cross 
     * Platform Network Layer)
     */
    class SDLNet_Socket
        : JCS_Socket
    {
    public:
        SDLNet_Socket();
        ~SDLNet_Socket();

        /** setter **/

        /** getter **/

    };
}

typedef JCS_Network::SDLNet_Socket SDLNet_Socket;

#endif // __SDL_NET_SOCKET_H__
