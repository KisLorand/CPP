#include <iostream>

// fuctions can be declared before the main function, but must be inplemented later
void WriteLine(std::string message);
void WriteLine(double message);
double CircleArea(double radius);

int main()
{
    WriteLine("Purr");
    double circleA = CircleArea(10);
    WriteLine(circleA);

    return 0;
}


void WriteLine(std::string message)
{
    std::cout << message  << std::endl;
}

void WriteLine(double message)
{
    std::cout << message  << std::endl;
}

double CircleArea(double radius)
{
    const double PI = 3.14159;
    return PI * radius * radius;
}