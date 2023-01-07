#include <iostream>

// Зад. 5
// Функция, която добавя елемент на края на масива
void add(int *&arr, int &size, int newElement)
{
    // Заделяме нова памет
    int *result = new int[size + 1];

    // Копираме всички стари елементи
    for (int i = 0; i < size; i++)
        result[i] = arr[i];

    // Накрая добавяме и новия
    result[size] = newElement;

    // Освобождаваме старата памет
    delete[] arr;

    // Обновяваме стойностите на аргументите. Затова и аргументите на функцията са подадени по референция.
    arr = result;
    size++;
}

// Зад. 6
// Функция, която добавя елемент на позиция index в масив
bool insertAt(int *&arr, int &size, int newElement, int index)
{
    // Проверка за коректност на индекса
    if (index < 0 || index > size)
    {
        return false;
    }

    // Заделяме нова памет
    int *result = new int[size + 1];

    // Копираме всички стари елементи преди index
    for (int i = 0; i < index; i++)
        result[i] = arr[i];

    // На позиция index слагаме новия елемент
    result[index] = newElement;

    // Копираме всички стари елементи след index
    for (int i = index + 1; i <= size; i++)
        result[i] = arr[i - 1];

    // Освобождаваме старата памет
    delete[] arr;

    // Обновяваме стойностите на аргументите. Затова и аргументите на функцията са подадени по референция.
    arr = result;
    size++;

    return true;
}

// Зад. 7
// Функция, която преоразмерява масив
bool resize(int *&arr, int &size, int newSize)
{
    // Проверка за коректност на новия размер
    if (newSize < 0)
        return false;

    // Заделяме нова памет
    int *result = new int[newSize];

    // Копираме всички стари елементи
    for (int i = 0; i < size && i < newSize; i++)
        result[i] = arr[i];

    // Слагаме нулеви стойности за потенциално новите елементи
    for (int i = size; i < newSize; i++)
        result[i] = 0;

    // Освобождаваме старата памет
    delete[] arr;

    // Обновяваме стойностите на аргументите. Затова и аргументите на функцията са подадени по референция.
    size = newSize;
    arr = result;

    return true;
}

// Зад. 8
// Функция, която копира елементите на един масив в друг
void copy(int *arrayFrom, int sizeFrom, int *&arrayTo, int &sizeTo)
{
    // Освобождаваме старата памет
    delete[] arrayTo;

    // Заделяме нова памет
    arrayTo = new int[sizeFrom];

    // Копираме всички елементи на arrayFrom в arrayTo
    for (int i = 0; i < sizeFrom; i++)
        arrayTo[i] = arrayFrom[i];

    // Обновяваме размера на arrayTo. Затова и аргументът на функцията е подаден по референция.
    sizeTo = sizeFrom;
}

// Помощна функция, която отпечатва елементите на масив
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    // Създаваме един динамичен масив
    int size = 3;
    int *arr = new int[size];
    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 2;

    // Добавяме му няколко елемента
    add(arr, size, 5);
    add(arr, size, -1);
    add(arr, size, 33);

    // Отпечатваме на екрана да видим дали елементите са действително добавени
    std::cout << "Result after add: " << std::endl;
    printArr(arr, size);

    // Добавяме му няколко елемента на конкретни индекси
    insertAt(arr, size, 10, 2);
    insertAt(arr, size, 72, 5);
    // Тук индексът е невалиден и очакваме да не видим новия елемент
    insertAt(arr, size, 101, 555);

    // Отпечатваме на екрана да видим дали елементите са действително добавени
    std::cout << "Result after insertAt: " << std::endl;
    printArr(arr, size);

    // Отрязваме размера на масива
    resize(arr, size, 3);
    // Отпечатваме на екрана да видим дали елементите са действително премахнати
    std::cout << "Result after resize: " << std::endl;
    printArr(arr, size);

    // Създаваме друг масив, в който ще копираме arr
    int copySize = 1;
    int *arrCopy = new int[copySize];

    // Копираме
    copy(arr, size, arrCopy, copySize);
    // Отпечатваме на екрана да видим дали елементите са действително копирани
    std::cout << "Result after copy: " << std::endl;
    printArr(arrCopy, copySize);

    // Не забравяме, че винаги трябва да зачистим паметта, която сме заделили динамично.
    delete[] arr;
    delete[] arrCopy;

    return 0;
}