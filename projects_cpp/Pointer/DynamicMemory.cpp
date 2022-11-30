#include <iostream>

int main()
{
    // dynamic memory -> memory that is allocated after the 
    //                   program is already compiled and running
    //                   Use the 'new' operator to allocate
    //                   memory in the heap instead of the stack

    // Useful when we don't know how much memory we will need.
    // makes our program more flexible,especially when accepting user input

    int *pNum = NULL;

    pNum = new int; //gets a new address 
    // when a new keyword is used, a delete must be called after it 
    // to prevent memory leaks, and to free up more 

    *pNum = 21;

    std::cout << "address : " << pNum << '\n';
    std::cout << "dereference/value : " << *pNum << '\n';

    delete pNum; // deleting the pointer


    //dynamic array size
    char *pGrades = NULL;
    int size;
    std::cout << "Choose array size : " << std::endl;
    std::cin >> size;

    pGrades = new char[size];

    for (int i=0; i<size; i++)
    {
        std::cout << "Enter garde number " << i+1 << ".\n";
        std::cin >> pGrades[i];
    }

    std::cout << "Grades: \n";
    for (int i=0; i<size; i++)
    {
        std::cout << pGrades[i] <<'\n';
    }

    delete[] pGrades;
 
    return 0;
}