#include <iostream>

int main()
{
    std::string cats[3]; //declare and array witha lenth of 3;
    cats[0] = "MirrMurr";
    cats[1] = "Shiba";
    cats[2] = "Cirmi";

    std::string cars[] = {"Corvette", "Mustang", "Diablo"};

    std::cout << "cars : " << cars << std::endl; // something like "0x61feb4", obj reference

    /* for (int i=0; i<cars->length(); i++)
    {
        std::cout << cars[i] << std::endl;
    }*/
    
    int sizeOfCars = sizeof(cars)/sizeof(std::string);
    //sizeof returns the size of a datatype in bytes
    for (int i=0; i<sizeOfCars; i++)
    {
        std::cout << cars[i] << " - memory size : " << sizeof(cars[i]) << " bytes" << std::endl;
    } 

    // foreach -> easier syntax, less flexible
    for (std::string car : cars)
    {
        std::cout << car << " - memory size : " << sizeof(car) << " bytes" << std::endl;
    } 

    return 0;
}