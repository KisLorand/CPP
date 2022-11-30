#include <iostream>
#include <cmath> //include math header file

int main()
{
    double x = 3.14;
    double y = 4;
    double z;

    std ::cout << std::max(x,y) << std::endl;

    double max = std::max(x,y);
    double min = std::min(x,y);

    double power = pow(2, 4);  //2^4 = 16
    double root = sqrt(9); // 9^(1/2) = 3
    double absoultevalue = abs(-4);

    double roundvalue = round(x);
    double rounddown = ceil(x);
    double roundup = floor(x);

    return 0;
}