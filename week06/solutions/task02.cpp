#include <iostream>

/*
    Да се напише фукнция void replace(int array[], int size, int find, int replace), която заменя всички срещания на find в array с replace.
*/

// Много подобна функция на тази от предната задача.
// Тук разликата е, че ако намерим даден елемент, го сменяме с друг.
// Функцията е void, защото не връща резултат. Тя изменя елементите на масива.
void replace(int array[], int size, int find, int replace)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == find)
        {
            // Не приключваме изпълнението на функцията тук, защото искаме да заменим всяко срещане на find в масива.
            array[i] = replace;
        }
    }

    return;
}

int main()
{
    int arr[] = {1, 3, 8, 5, 1};

    // След изпълнението на функцията, arr ще е променен
    replace(arr, 5, 1, 7);

    // Извикваме функцията пак, което значи, че arr пак ще се промени
    replace(arr, 5, 7, 4);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    return 0;
}