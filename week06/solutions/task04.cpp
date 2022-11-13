#include <iostream>

/*
    Да се напише булева функция, която проверява дали елементите на един масив образуват аритметична прогресия.
*/

// Една поредица от числа образува аритметична прогресия, ако разликата между всеки два елемента е една и съща.
// Което е равносилно на разликата между всеки два елемента да е равна на разликата между първите два елемента.
bool isArithmeticSequence(int array[], int size)
{
    // Тривиалният случай. Всяка поредица от 2 или по-малко числа е аритметична прогресия.
    if (size <= 2)
        return true;

    // Тук се вижда, защо горната проверка е важна. Ако програмата е стигнала до тук, знаем, че имаме поне два елемента.
    // Т.е. спокойно можем да достъпим елементите на индекс 0 и 1.
    int diff = array[1] - array[0];

    // Обхождаме масива и правим проверка за разликата на всеки два съседни елемента.
    // Пак внимаваме да не достъпваме елементи извън рамките на масива.
    for (int i = 0; i < size - 1; i++)
    {
        int currentDiff = array[i + 1] - array[i];

        if (currentDiff != diff)
            return false;
    }

    return true;
}

int main()
{
    int arr[] = {1, 3, 5, 7};
    int arr2[] = {1, 3, 5, 8};

    std::cout << isArithmeticSequence(arr, 4) << std::endl;
    std::cout << isArithmeticSequence(arr2, 4) << std::endl;

    return 0;
}