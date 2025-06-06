
#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace hde
{
    class BindingSocket: public SimpleSocket
    {
        public:
            // Constructor
            BindingSocket(
                int domain, 
                int service, 
                int protocol, 
                int port, 
                u_long interface
            );
            // ~BindingSocket();

            // virtual function from parent
            int connect_to_network(int sock, struct sockaddr_in address);

    }
} // namespace hde


#endif /* SimpleSocket_hpp */
