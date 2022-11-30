#include <iostream>

// switch can only use integer type

enum Day
{
    monday, 
    tuesday, 
    wednesday, 
    thursday, 
    friday, 
    saturday, 
    sunday
};
// as base: enum Day::monday=0;

int main()
{
    Day today = wednesday;

    switch(today)
    {
        case 0: //monday
            std::cout << "It's Monday my Man!";
            break;
        case wednesday: 
            std::cout << "It's Wednesday my dudes!";
            break;
        default:
            std::cout << "Understandable, have a nice day.";
            break;
    }
    return 0;
}