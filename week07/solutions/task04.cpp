#include <iostream>

/*
    Напишете булева функция, която приема матрица NxN (N<=100), и която връща true,
    ако елементите по главния диагонал на матрицата са равни на елементите по вторичния диагонал и false в противен случай.
*/

// Първо ще напишем една функция, която печата елементите по главния диагонал.
void printMainDiagonal(int matrix[100][100], int n)
{
    for (int i = 0; i < n; i++)
        // Елементите по главния диагонал се характеризират с това, че имат еднакъв индекс на ред и колона.
        std::cout << matrix[i][i];
}

// След това ще напишем една функция, която печата елементите по вторичния диагонал.
void printMainDiagonal(int matrix[100][100], int n)
{

    // Елементите на главния диагонал почват от първи ред, последна колона.
    int i = 0;
    int j = n - 1;
    while (i < n && j >= 0)
    {
        std::cout << matrix[i][j];

        // На всяка стъпка отиваме на следващия ред и на предишната колона
        i++;
        j--;
    }
}

// Комбинираме написаното от предните две функции, за да решим задачата
bool equalDiagonals(int matrix[100][100], int n)
{
    for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
    {
        int mainDiagonalElem = matrix[i][i];
        int secondaryDiagonalElem = matrix[i][j];

        if (mainDiagonalElem != secondaryDiagonalElem)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int matrix[100][100] = {
        {1, 2, 1},
        {1, 2, 4},
        {4, 2, 4}};

    std::cout << equalDiagonals(matrix, 3) << std::endl;

    return 0;
}