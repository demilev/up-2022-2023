#include <iostream>

/*
    Напишете функции `void populateArr(int* start, int size)` и `void printArr(int* start, int size)`,
    които приемат указател към първия елемент на масив и съответно въвеждат от клавиатурата и печатат елементите на масива,
    използвайки указатели вместо синтаксиса за достъп по индекс `arr[i]`.
*/

// Приемаме указател към първия елемент на масива и го обхождаме, местейки указателя
void printArr(int *start, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(start + i) << " ";
    }
}

// Същата функция като предната, но с разликата, че операцията, която извършваме
// върху всеки елемент на масива, е различна.
void populateArr(int *start, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> *(start + i);
    }
}

int main()
{
    int arr[100];
    int size;
    std::cin >> size;

    // Подаваме arr директно като параметър на функциите, защото arr е указател към първия елемент.
    populateArr(arr, size);
    printArr(arr, size);

    return 0;
}