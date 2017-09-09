/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __ASIO_SOCKET_H__
/**
 * $File: Asio_Socket.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __ASIO_SOCKET_H__


#include "Socket_StdAfx.h"


namespace JCS_Network
{

    /**
     * @class Asio_Socket
     * @brief Socket Layer using Boost Asio. (Cross Platform Network Layer)
     */
    class Asio_Socket
        : public JCS_Socket
    {
    private:
        //boost::asio::io_service m_IoService;

    public:
        Asio_Socket();
        ~Asio_Socket();


        /** setter **/

        /** getter **/

    };

}

typedef JCS_Network::Asio_Socket Asio_Socket;

#endif // __ASIO_SOCKET_H__

