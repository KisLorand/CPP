
#include "SimpleSocket.hpp"

hde::SimpleSocket::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    address.sin_family = domain;
    address.sin_port = htons(port); //int -> bites are in an order for the host system => order for the network : htons function is used for that
    address.sin_addr.s_addr = interface; //your IP address
    connection = socket(domain, service, protocol);
}
    
hde::SimpleSocket::~SimpleSocket()
{

}