#include <iostream>

/*
    Напишете функция, която приема матрица NxМ (N,М<=100) и отпечатва на екрана на нови редове най-големия елемент на всеки ред на матрицата.
*/

// Ще преизползваме функцията за намиране на най-голям елемент в масив, която написахме миналата седмица.
int maxElement(int arr[], int size)
{
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

void printMaxElements(int matrix[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        // Тук виждаме, че е полезно да помним, че матрицата е масив, чиито елементи са масиви.
        // matrix[i] абстрактно казано е редът с индекс i, 
        // но на практика е просто един масив и като такъв можем да го подадме на функция, която приема масив.
        std::cout << maxElement(matrix[i], cols) << std::endl;
    }
}

int main()
{
    int matrix[100][100] = {
        {1, 2, 3},
        {1, 2, 4},
        {5, 2, 4}};

    printMaxElements(matrix, 3, 3);

    return 0;
}