#include <iostream>

/*
    Напишете програма, която отпечатва на екрана всички подмножества на на дадено множество от цели числа.
*/

// Помощна функция, която отпечатва масив по "красив" начин
void printSet(int arr[], int n)
{
    std::cout << "{";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

// Функция, която печата всички подмножества на първите n елемента от масива set.
// subSet ще е масив, който държи текущо изграденото подмножество
void printPowerSet(int set[], int n, int subSet[], int subSetSize)
{
    // Ако n е нула, отепчатваме текущо изграденото подмножество
    if (n == 0)
    {
        printSet(subSet, subSetSize);
        return;
    }

    // За да изградим всички подмножества на първите n елемента, ще изградим всички подмножества,
    // които съдържат n-ия елемент и всички, които не го съдържат.

    // Добавяме n-ия елемент към текущото подмножество
    subSet[subSetSize++] = set[n - 1];

    // Печатаме всички подмножества на първите n - 1 елемента
    printPowerSet(set, n - 1, subSet, subSetSize);

    // Backtracking! - премахваме n-ия елемент
    subSetSize--;

    // Печатаме всички подмножества на първите n - 1 елемента
    printPowerSet(set, n - 1, subSet, subSetSize);
}

int main()
{
    int set[3] = {1, 2, 3};
    int subSet[3];

    printPowerSet(set, 3, subSet, 0);
}