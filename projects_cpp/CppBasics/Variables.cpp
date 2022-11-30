#include <iostream>

int main()
{
    int x; //declaration
    x = 7;

    //int - whole number 
    int y = 4.20; // gets truncated to 4

    //double - number inclouding decimal
    double price = 10.991;

    // char - single character
    char letter = 'A';
    // char initial = 'BC' -> gets an overflow in conversion 
    char currency = '$';

    //boolean - true/false
    bool isCat = true;

    //string -> objects that represent a sequence of text, ~char[]
    std::string name = "Joze";


    std::cout << price;

    return 0;
}