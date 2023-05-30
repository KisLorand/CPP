
#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>

namespace hde
{
    class SimpleSocket
    {
    private:
        /* data */
    public:
        SimpleSocket(int domain, int service, int protocol);
        ~SimpleSocket();
    };
    
} // namespace hde


#endif /* SimpleSocket_hpp */
