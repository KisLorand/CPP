#include <iostream>


int main()
{
    // nullptr -> null pointer : when a pointer is not pointing at anything (obj have not been instanciated)

    int *pointer = nullptr; // can be assignd later
    int x = 123;

    pointer = &x;// comments to see the change

    if (pointer == nullptr)
    {
        std::cout << "pointer has no address\n"; 
        // std::cout << *pointer << "\n"; -> do not try to do this
        // a nullptr cannot be dereferenced
    }
    else
    {
        std::cout << "address has assigned\n";
        std::cout << *pointer << "\n";
    }

    return 0;
}