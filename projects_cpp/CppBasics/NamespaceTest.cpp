#include <iostream>

namespace first{
    int x = 69;
    int a = 300;
}
namespace second{
    int x = 420;
}

int main()
{
    // namespace -> provides a solution for preventing name conflictsin large projects, Each entity needs a unique name. A namespace allows for identically named entities as long as the namespaces are different.

    using namespace first; // using entities form 'first' namespace, the 

    int x = 0;

    std::cout << x << '\n';
    std::cout << first::x << '\n';
    std::cout << second::x << '\n';
    // :: first resolution operator

    std::cout << a << '\n';

    return 0;
}