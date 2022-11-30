#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t; 
//typedef syntax ends with _t

typedef std::string text_t;
//a prefered syntax is 'using' , instead of 'typedef'
using number_t = int;

int main()
{
    pairlist_t pairlist;
    text_t name = "Johann";
    number_t age = 21;

    std::cout << name << '\n' << age ;

    return 0;
}