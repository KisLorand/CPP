
#include "SimpleSocket.hpp"

hde::SimpleSocket::SimpleSocket::SimpleSocket(int domain, int service, int protocol)
{
    connection = socket(domain, service, protocol);
}
    
hde::SimpleSocket::~SimpleSocket()
{

}