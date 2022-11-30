#include <iostream>

void displayArray(int array[], int size);
void BubbleSort(int array[], int size);

int main()
{
    int array[] = {911, 2, 85, 99, 69, 420, 7};
    int size = sizeof(array)/sizeof(array[0]);

    displayArray(array, size);

    BubbleSort(array, size);

    displayArray(array, size);

    return 0;
}

// O(n^2)
void BubbleSort(int array[], int size)
{
    int tmp;
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

void displayArray(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}