#include <iostream>

int main()
{
    int count = 7;
    int* pCount = &count;

    std::cout << &count << std::endl;
    std::cout << pCount << "   " << &pCount << std::endl;

    return 0;
}