#include <iostream>
#include <cmath>

int main()
{
    double a;
    double b;
    double c;

    std::cout << "Enter a lenght for side A : ";
    std::cin >> a;
    std::cout << "Enter a lenght for side B : ";
    std::cin >> b;

    std::cout << "C = " << sqrt(pow(a,2)+pow(b,2));

    return 0;
}