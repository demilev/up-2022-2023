#include <iostream>

/*
    Нека имаме масив от реални числа `double arr[50]`, реално число `double expected` и `int size` - размер на масива (`size` <= 50).
    Напишете функция, която добавя към масива толкова нули в края, така че средното аритметично на елементите на масива (след добавянето на нулите)
    да е по-малко или равно на `expected`, и така че, ако се добавят по-малко нули, средното аритметично да е по-голямо от `expected`.
*/

void balance(double arr[50], int &size, double expectedAverage)
{
    // Първо намираме средно аритметичното на елементите на масива
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double avg = sum / size;

    // Докато то е по-голямо от очакваното
    while (avg > expectedAverage)
    {
        // Добавяме една нула накрая
        arr[size] = 0;
        // Увеличаваме размера
        size++;
        // Презичисляваме средното
        avg = sum / size;
    }

    return;
}

int main()
{
    int size = 3;
    double arr[50] = {1, 2, 3};
    double expected = 1;

    balance(arr, size, expected);

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}