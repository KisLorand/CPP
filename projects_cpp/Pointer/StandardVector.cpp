#include <iostream>
#include <vector>

template <typename T>
void printVectorData(std::vector<T> &vector);

template <typename T>
void printVectorElements(std::vector<T> &vector);

template <typename T>
void printVectorElements_ByPointers(std::vector<T> &vector);

int main()
{
    std::vector<int> g1;
    printVectorData(g1);

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    printVectorData(g1);
    printVectorElements(g1);
    printVectorElements_ByPointers(g1);

    return 0;
}

template <typename T>
void printVectorData(std::vector<T> &vector)
{
    std::cout << "Vector g1" << '\n';
    std::cout << "Address: " << &vector << '\n';
    std::cout << "Size: " << vector.size() << '\n';
    std::cout << "Capacity : " << vector.capacity() << '\n';
    std::cout << "Max_Size : " << vector.max_size() << '\n';
    std::cout <<'\n';
}

template <typename T>
void printVectorElements(std::vector<T> &vector)
{
    std::cout << "Vector elements are: ";
    for (auto it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
    std::cout <<'\n';
}

template <typename T>
void printVectorElements_ByPointers(std::vector<T> &vector)
{
    // memory pointer pointing to the
    // first element
    int* pos = vector.data();

 
    // prints the vector
    std::cout << "The vector elements are: \n";
    for (int i = 0; i < vector.size(); ++i)
        std::cout << pos << " : " << *pos++ << "\n";
}
