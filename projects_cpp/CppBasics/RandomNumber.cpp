#include <iostream>
#include <ctime> // for time()

int main()
{
    // pseudo random
    srand(time(NULL)); 
    // time gives the current time;
    // the current time is used as a seed for the random number

    int num = rand();
    
    std::cout << num << "\n";

    int diceroll = (rand() % 6) + 1;
    std::cout << diceroll;

    return 0;
}