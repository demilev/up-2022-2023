#include <iostream>

/*
    Да се напише булева функция, която приема два масива и връща true, ако всички елементи на първия масив са по-малки или равни от всички елементи на втория масив и false в противен случай.
*/

// Решение, което директно следва условието на задачата.
bool solution(int first[], int sizeFirst, int second[], int sizeSecond)
{
    for (int i = 0; i < sizeFirst; i++)
    {
        // За всеки елемент на първия масив, обхождаме изцяло втория масив
        for (int j = 0; j < sizeSecond; j++)
        {
            // Ако срещнем елемент във втория масив, който е по-малък от текущия елемент от първия масив,
            // то това означава, че не е вярно, че всички елементи на първия масив са по-малки от всички елементи на втория масив.
            if (first[i] > second[j])
                return false;
        }
    }

    return true;
}

// Помощна функция за намиране на най-голям елемент в масив.
int maxElement(int arr[], int size)
{
    // Ако масивът е празен, нащата функция ще има недефинирано поведение.
    int candidate = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > candidate)
        {
            candidate = arr[i];
        }
    }

    return candidate;
}

// Помощна функция за намиране на най-малък елемент в масив.
int minElement(int arr[], int size)
{
    // Ако масивът е празен, нащата функция ще има недефинирано поведение.
    int candidate = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < candidate)
        {
            candidate = arr[i];
        }
    }

    return candidate;
}

// Решение, което е по-ефикасно от първото. Ще си говорим за това, когато стигнем темата за сложности и алгоритми.
bool improvedSolution(int first[], int sizeFirst, int second[], int sizeSecond)
{
    int maxElementFirst = maxElement(first, sizeFirst);
    int minElementSecond = minElement(second, sizeSecond);

    // Свеждаме задачата до нещо по-прост - най-големият елемент на първия масив да е по-малък или равен от най-малкият елемент на втория масив.
    return maxElementFirst <= minElementSecond;
}

int main()
{
    int first[5] = {1, 2, 10, 5, 3};
    int second[5] = {11, 12, 110, 15, 13};

    std::cout << solution(first, 5, second, 5) << std::endl;
    std::cout << improvedSolution(first, 5, second, 5) << std::endl;

    return 0;
}