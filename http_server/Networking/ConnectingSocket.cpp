
#include "ConnectingSocket.hpp"

// Constructor implementation
hde::ConnectingSocket::ConnectingSocket(
    int domain, int service, int protocol, int port, u_long interface
  ) : SimpleSocket(
    domain, service, protocol, port, interface
  )
{
    // passing the result of the binding implementation method (connect_to_network) 
    //      to the parent method 
    // connect_to_network is implemented here, in Binding socket;
    // set_connection, get_sock, get_address, get_connection 
    //      are in SimpleSocket(Parent Class)
    set_connection(
        connect_to_network(get_sock(), get_address())
    );
    test_connection(get_connection());
}

// Implementation of connect_to_network virtual funtcion (from the Parent class)
int hde::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address) 
{
    return connect(sock, (struct sockaddr_in*)&address, sizeof(address));
    // (struct sockaddr_in*)&address -> convert the "address of" the 'address' variable
    //      to a type -> a pointer pointing at a 'struct sockaddr_in' type
}