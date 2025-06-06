
#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace hde
{
    class ConnectingSocket: public SimpleSocket
    {
        public:
            // Constructor
            ConnectingSocket(
                int domain, 
                int service, 
                int protocol, 
                int port, 
                u_long interface
            );
            // ~ConnectingSocket();

            // virtual function from parent
            int connect_to_network(int sock, struct sockaddr_in address);

    }
} // namespace hde


#endif /* ConnectingSocket_hpp */