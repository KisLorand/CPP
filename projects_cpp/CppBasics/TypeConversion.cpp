#include <iostream>
#include <string>

int main()
{
    //implicit - automatic
    int x = 3.14; // 3

    // explicit precede value with new data type
    double y = (int) 4.52;

    std::cout << x << '\n' << y << '\n' ;

    char letter = 100; // d (from ascii code)

    std::cout << letter << std::endl;

    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions * 100;

    std::cout << score << std::endl;

    // cout << (insertion operator)
    // cin >> (extraaction operator)
    std::string name;
    std::cout << "what is your name?";

    std::cin >> name; // store value in name, cannot deal with whitespaces

    std::cout << "Hello " << name << std::endl;

    std::string fullname;
    std::cout << "what is your full name?";

    std::getline(std::cin >> std::ws, fullname);
    // can check whitespaces (needs <string> included)
    // if cin is followed by a getline, the first parameter needs a '>> sid:ws' to buffer the input/ remove whitespaces and newlines

    std::cout << "Hello " << fullname << ", nice to meet you.\n";
    

    return 0;
}