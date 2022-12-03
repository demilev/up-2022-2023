#include <iostream>

/*
    Напишете рекурсивна функция, която сравнява лексикографски два символни низа.
*/

int compare(char *first, char *second)
{
    // Пример за рекурсивна функция с повече от едно дъно.

    // Празните низове са равни
    if (*first == 0 && *second == 0)
        return 0;

    // Празният низ е по-малък от всеки непразен низ
    if (*first == 0 && *second)
        return -1;

    // Непразен низ е по-голям от празния такъв
    if (*first && *second == 0)
        return 1;

    // Сравняваме текущите букви на двата низа
    if (*first > *second)
        return 1;
    if (*first < *second)
        return -1;
    else
        // Само ако са равни текущите символи, викаме рекурсивно функцията за следващите
        return compare(first + 1, second + 1);
}

int main()
{

    char arr[] = "hello";
    char arr1[] = "heLlo";

    std::cout << compare(arr, arr1) << std::endl;

    return 0;
}