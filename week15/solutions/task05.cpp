#include <iostream>

/*
    Нека е дадена булева матрица NxN (N <= 100), която представя познанствата между хората на дадено парти.
    Напишете функция, която приема такава матрица и връща(ако съществува) човека, който всеки познава.
*/

// Трябва да намерим индекса на колоната, в която има само стойност истина, защото това означава, че всеки познава човека с този индекс.
int popular(bool matrix[100][100], int size)
{
    for (int j = 0; j < size; j++)
    {
        // Обхождаме текущата колона и проверяваме дали отговаря на условието
        bool knownByAll = true;
        for (int i = 0; i < size; i++)
        {
            if (matrix[i][j] == false)
            {
                knownByAll = false;
            }
        }

        // Само ако отговаря на условиет можем да приключим изпълнението на функцията.
        // В противен случай продължаваме да въртим цикъла.
        if (knownByAll)
        {
            return j;
        }
    }

    return -1;
}

int main()
{

    bool matrix[100][100] = {
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 1}};

    std::cout << popular(matrix, 4);

    return 0;
}