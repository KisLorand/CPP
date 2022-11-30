#include <iostream>

int myNum = 7; //global var

void print();
void print(int num);

int main()
{
    int myNum = 9;
    print(myNum); // 9

    print(); // 0

    print( ::myNum ); // 7
    // :: -> scope resolution operator, steps back (to one scope)
}

void print()
{
    std::cout << 0 << std::endl;
}

void print(int num)
{
    std::cout << num << std::endl;
}