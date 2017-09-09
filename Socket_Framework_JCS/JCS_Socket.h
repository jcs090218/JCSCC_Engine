/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_SOCKET_H__
/**
 * $File: JCS_Socket.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_SOCKET_H__



namespace JCS_Network
{

    //====================================================================================
    // Name : JCS_Socket 
    //
    // Description : Interface for JCSCC Socket. Design the socket 
    //      interface here.
    //====================================================================================
    class JCS_Socket
    {
    public:
        virtual ~JCS_Socket() { }
    };

}

typedef JCS_Network::JCS_Socket JCS_Socket;

#endif // __JCS_SOCKET_H__

