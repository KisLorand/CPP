#include <iostream>

int main()
{
    // fill() -> fills a range of elements with a specified value
    //          fill(begin, end, value)

    const int SIZE = 10;
    std::string foods[SIZE];
    fill(foods, foods+(SIZE/2), "Chicken soup");
    fill(foods+(SIZE/2), foods+SIZE, "Mashed Potatoes");
    // 5 chicken soup, 5 Mashed Potatoes;

    for (std::string food : foods)
    {
        std::cout << food << '\n';
    }

    return 0;
}