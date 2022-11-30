#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}
// "generic" type -> we don't know the exact type or want to be used for multiple types
template <typename T, typename U>
auto max(T x, U y)
{
    return (x > y) ? x : y;
}
//auto keyword returns T or U, the type of the return statement 

int main()
{
    std::cout << max(1,2) << '\n';
    std::cout << max(1.99,2.73) << '\n';
    std::cout << max('A','S') << '\n';

    std::cout << max(2,'S') << '\n';

    return 0;
}