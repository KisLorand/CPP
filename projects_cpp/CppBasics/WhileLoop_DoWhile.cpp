#include <iostream>
#include <string>

int main()
{
    int number;
    
    do {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while (number < 0);

    std::cout << "The number you typed in is " << number;

    return 0;
}