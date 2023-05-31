
#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace hde
{
    class SimpleSocket
    {
    private:
        struct sockaddr_in address;      
        int connection;
    public:
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
        ~SimpleSocket();
    };
    
} // namespace hde


#endif /* SimpleSocket_hpp */
