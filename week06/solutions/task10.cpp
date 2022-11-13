#include <iostream>

/*
    Да се напише програма, която кара потребителя да въведе масив от цели числа и в нов масив на i-тата позиция да се записва броя на числата,
    които са по-малки от i-тия елемнт на първия масив и стоят на позция по-голяма от него(т.е. са вдясно от него).
*/

void smallerElementsCount(int original[], int size, int result[])
{
    for (int i = 0; i < size; i++)
    {
        // Както знаем, на всяко изпълние на цикъла, тази променлива ще бъде унищожавана и създавана наново.
        int countSmaller = 0;
        // За всеки елемент на масивa, обхождаме всички елементи, които са след него.
        for (int j = i + 1; j < size; j++)
        {
            if (original[i] > original[j])
                countSmaller++;
        }

        result[i] = countSmaller;
    }

    return;
}

int main()
{
    int original[6] = {1, 2, 3, 4, 2, 3};
    int result[6];

    smallerElementsCount(original, 6, result);

    for (int i = 0; i < 6; i++)
        std::cout << result[i] << " ";

    std::cout << std::endl;

    return 0;
}