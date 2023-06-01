
#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include <SimpleSocket.hpp>

namespace hde
{
    class BindingSocket: public SimpleSocket
    // public inheritance - to access all functions of the parent class
    {
    public:
        BindingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface);
    };
} // namespace hde


#endif /* BindingSocket_hpp */