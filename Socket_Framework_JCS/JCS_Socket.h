/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_SOCKET_H__
#define __JCS_SOCKET_H__



namespace JCS_Network
{

    //------------------------------------------------------------------------------------
    // Name : JCS_Socket 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JCS_Socket
    {
    public:
        virtual ~JCS_Socket() { }
    };

}

typedef JCS_Network::JCS_Socket JCS_Socket;

#endif // __JCS_SOCKET_H__

