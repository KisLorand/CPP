
#include "SimpleSocket.hpp"

hde::SimpleSocket::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port); //int -> bites are in an order for the host system => order for the network : htons function is used for that
    address.sin_addr.s_addr = htonl(interface); //your IP address, same type of conversion

    // Establish socket
    sock = socket(domain, service, protocol);
    test_connection(sock);

    /* // Establish network connection
    connection = establish_network_connection(sock, address);
    test_connection(connection); */
}
    
hde::SimpleSocket::~SimpleSocket()
{

}

void hde::SimpleSocket::test_connection(int item_to_test) 
{
    if (item_to_test < 0)
    {
        perror("failed to connect.");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in hde::SimpleSocket::get_address()
{
    return address;
}

int hde::SimpleSocket::get_sock()
{
    return sock;
}

int hde::SimpleSocket::get_connection()
{
    return connection;
}

// Setter funcitons
void hde::SimpleSocket::set_connection(int con)
{
    connection = con;
}