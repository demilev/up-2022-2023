#include <iostream>

/*
    Да се напише фукнция bool contains(int array[], int size, int elem), която проверява дали elem е елемент на array.
*/

// Класическа функция. Много често ще ни се налага да търсим елемент в масив.
// Функцията приема масива и размерът му.
bool contains(int array[], int size, int elem)
{
    for (int i = 0; i < size; i++)
    {
        // Ако намерим срещане на elem, директно връщаме true. Елементът е намерен.
        if (array[i] == elem)
            return true;
    }

    // Ако сме обходили масива, значи не сме срещнали elem.
    return false;
}

int main()
{
    int arr[5] = {1, 2, 10, 5, 3};

    std::cout << contains(arr, 5, 3) << std::endl;
    std::cout << contains(arr, 5, -6) << std::endl;

    return 0;
}