#include <iostream>

int main()
{
    // '\n' has better performance
    std::cout << "meaningful message" << "\n";
    // endl(ine) will flush the output buffer
    std::cout << "meaningful message" << std::endl;
    std::cout << "not so meaningful message" << std::endl;
    return 0;
}

