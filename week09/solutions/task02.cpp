#include <iostream>

/*
    Пренапишете функция от предната задача, като нека този път вместо да връща указател към най-големия елемент в масива,
    да приема трети параметър, който да е указател и който след изпълнение на функцията да сочи към най-големия елемент на масива.
*/

// Аналогично решение на предишното с разликата, че този път приемаме референция към указател, който
// ще насочим към най-големия елемент на масива вместо да го връщаме като резултат от функцията.
void maxElement(int *start, int *end, int *&maxElement)
{
    maxElement = start;

    while (start <= end)
    {
        if (*start > *maxElement)
            maxElement = start;

        start++;
    }
}

int main()
{
    int arr[] = {5, 8, -2};
    int *maxElementPtr;

    maxElement(arr, arr + 2, maxElementPtr);

    std::cout << *maxElementPtr;

    return 0;
}