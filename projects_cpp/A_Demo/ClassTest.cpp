#include <iostream>

class BasicClass
{
    public:
        int count;

        BasicClass()
        {
            this->count = 0;
            std::cout << "Class 0 created" << std::endl;
        }

        BasicClass(int number)
        {
            this->count = number;
            std::cout << "Class " << number << " created" << std::endl;
        }

        ~BasicClass()
        {
            std::cout << "Class " << count << " deleted" << std::endl;
        }
};

class ComplexClass
{
    public:
        BasicClass cl;
        BasicClass* pCl;

        ComplexClass()
        {
            auto pBasicCl = new BasicClass(7);
            this->pCl = pBasicCl;
            this->cl = *pCl;

            std::cout << "Complex Class created" << std::endl;
        }

        ~ComplexClass()
        {
            //delete pCl;
            std::cout << "Complex Class deleted" << std::endl;
        }
};

int main()
{
    int v = 5;
    int* pV = &v;

    BasicClass* pBasic1 = new BasicClass(v);
    delete pBasic1;

    ComplexClass* pComplex1 = new ComplexClass();
    delete pComplex1;

    std::cout << v << std::endl;

    return 0;
}


/*
Class 5 created
Class 5 deleted
Class 0 created -> for the copy in : auto pBasicCl = new BasicClass(7);  base ctor call
Class 7 created
Complex Class created
Complex Class deleted
Class 7 deleted
5 
*/