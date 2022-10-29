#include <iostream>

/*

    Да се напише функция `int arithSequenceSum(int start, int difference, int n)`, която връща сумата на
    първите n числа в аритметична прогресия с първи член start и разлика difference.
*/

// Решение с обхождане на членовете от прогресията и сумирането им
int arithSequenceSum(int start, int difference, int n)
{
    int current = start; // променлива, която ще пази текущия член на прогресията
    int i = 1;           // променлива, която ще пази номера на теукищия член на прогресията
    int sum = 0;         // променлива, която ще акумулира сумата

    // Изпълняваме цикъла за първите n члена
    while (i <= n)
    {
        sum += current;        // към сумата добавяме текущия член
        current += difference; // изчисляваме следващия член
        i++;
    }

    return sum;
}

// Решение с директно използване на формулата за сума - (A1 + An) * n / 2
int arithSequenceSumFormula(int start, int difference, int n)
{
    //       A1                 An
    return (start + (start + (n - 1) * difference)) * n / 2;
}

int main()
{
    // 1, 3, 5, 7, 9
    std::cout << arithSequenceSum(1, 2, 5) << std::endl;
    std::cout << arithSequenceSumFormula(1, 2, 5) << std::endl;
}