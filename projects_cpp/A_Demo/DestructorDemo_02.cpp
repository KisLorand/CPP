#include <iostream>

class Number
{
    public:
        int* pValue;

        Number(int val)
        {
            pValue = (int *) malloc(sizeof(int));
            *pValue = val;
            std::cout << "Number " << *pValue << " constructed." << std::endl; 
            std::cout << "Number value address " << pValue << std::endl; 
        }

        ~Number()
        {
            std::cout << "Number " << *pValue << " destructed." << std::endl; 
            std::cout << "Number value address " << pValue << std::endl; 
            free(pValue);
        }
};

void test()
{
    Number number(3);
}

int main()
{
    Number *nine = new Number(9);
    delete nine;

    Number num(7);

    test();

    return 0;
}