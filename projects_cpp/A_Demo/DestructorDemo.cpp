#include <iostream>

class Number
{
    public:
        int value;

        Number(int val)
        {
            value = val;
            std::cout << "Number " << value << " constructed." << std::endl; 
        }

        ~Number()
        {
            std::cout << "Number " << value << " destructed." << std::endl; 
        }
};

void test()
{
    Number number(9);
}

int main()
{
    Number num(7);

    test();

    return 0;
}