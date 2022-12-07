#include <iostream>

int main()
{
    int value = 7;
    int* address = &value;

    std::cout << address << std::endl;

    return 0;
}