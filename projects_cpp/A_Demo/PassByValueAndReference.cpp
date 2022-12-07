#include <iostream>

void swap(std::string x, std::string y);
void swapRef(std::string &x, std::string &y);

int main()
{
    std::string x = "A reasonably long string";
    std::string y = "wasd";

    std::cout << "Pass values\n"; 
    swap(x, y);

    std::cout << "ref in main\n";
    std::cout << "X : " << x << " , ref: " << &x << '\n';
    std::cout << "Y : " << y << " , ref: " << &y << '\n';

    std::cout << '\n';
    std::cout << "Pass references\n";
    swapRef(x, y);

    std::cout << "ref in main\n";
    std::cout << "X : " << x << " , ref: " << &x << '\n';
    std::cout << "Y : " << y << " , ref: " << &y << '\n';
    // after the swap X has the same reference but different value
    return 0;
}

void swap(std::string x, std::string y)
{
    std::cout << "  ref in function\n";
    std::cout << "  X : " << x << " , ref: " << &x << '\n';
    std::cout << "  Y : " << y << " , ref: " << &y << '\n';

    std::string tmp;
    tmp = y;
    y = x;
    x = tmp;
}

void swapRef(std::string &x, std::string &y)
{
    std::cout << "  ref in function\n";
    std::cout << "  X : " << x << " , ref: " << &x << '\n';
    std::cout << "  Y : " << y << " , ref: " << &y << '\n';

    std::string tmp;
    tmp = y;
    y = x;
    x = tmp;
}