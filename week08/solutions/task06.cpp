#include <iostream>

/*
    Напишете функция `void count(int* arr, int size, int find, тип occurences)`,
    която в променливата occurences запазва броя на срещанията на променливата `find` в масива `arr`.
*/

// Всяка промяна, която правим върху occurences, ще се отрази
// и върху променливата, с която сме извикали функцията.
void count(int *arr, int size, int find, int &occurrences)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == find)
            occurrences++;
    }
}

int main()
{
    int arr[] = {1, 2, 1, 1, 3, 4, 5};
    int numberOfOnes = 0;

    count(arr, 7, 1, numberOfOnes);

    std::cout << numberOfOnes << std::endl;

    return 0;
}