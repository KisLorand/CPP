#include <iostream>

int main()
{
    // memory address -> a location in the memory where the data is stored
    // & (memory access operator)

    std::string name = "Shiba";
    int age = 21;
    bool isStudent = false;

    std::cout << &name <<'\n'; //some hexadecimal number, like 0x61fef4
    std::cout << &age <<'\n'; // 0x61fef0
    std::cout << &isStudent <<'\n'; // 0x61feef

    // the difference between "name" and "age" is greater than "age" and "isStudent", because a string takes up more space in memory

    return 0;
}