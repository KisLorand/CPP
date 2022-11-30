#include <iostream>


int main()
{
    // pointer -> a variable that stores a memory address of an other variable

    // & -> address of operator
    // * -> deference operator

    std::string name = "Shiba";

    // saving the address (&name) of name in a pointer (starts with p)
    std::string *pName = &name;

    std::cout << "Pointer : " << pName << '\n';
    std::cout << "Pointer Value: " << *pName << '\n';

    std::cout <<'\n';

    int age = 7;
    int *pAge = &age;
    std::cout << "Variable : " << age << '\n';
    std::cout << "Variable Address : " << &age << '\n';
    std::cout << "Pointer : " << pAge << '\n';
    std::cout << "Value at Pointer : " << *pAge << '\n';

    std::cout <<'\n';

    std::string cars[] = {"Corvette", "Mustang", "Diablo"};
    std::string *pCars = cars; // &cars -> error, the array is already an address
    std::cout << "Array Address (cars[]): " << cars << '\n';
    std::cout << "Pointer : " << pCars << '\n';
    std::cout << "Pointer Dereference (cars[0]): " << *pCars << '\n';

    return 0;
}