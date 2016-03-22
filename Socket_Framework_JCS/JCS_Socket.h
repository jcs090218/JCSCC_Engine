#ifndef __JCS_SOCKET_H__
#define __JCS_SOCKET_H__



namespace JCS_Network
{

    class JCS_Socket
    {
    public:
        virtual ~JCS_Socket() { }
    };

}

typedef JCS_Network::JCS_Socket JCS_Socket;

#endif // __JCS_SOCKET_H__

