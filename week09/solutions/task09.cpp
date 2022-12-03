#include <iostream>

/*
    Напишете функция, която прима матрица NxМ (N,М<=100), която е съставена само от 0 и 1
    и която проверява дали има път от клетката с координати (0, 0) до клетка с координати (N - 1, M - 1)
    съставен само от 1ици(движението от една клетка в друга става по диагонал, надолу по вертикал и надясно по хоризонтал).
*/

// Помощна функция, която ще ни казва дали можем да продължим с клетка (i, j)
bool canMove(bool matrix[100][100], int rows, int cols, int i, int j)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return matrix[i][j];
}

// Помощна функция, която ще проверява дали в матрицата matrix с rows на брой редове и cols на брой колони
// има път между клетка с координати (fromRow, fromCol) и клетка с координати (toRow, toCol)
bool pathExistsHelper(bool matrix[100][100], int rows, int cols, int fromRow, int fromCol, int toRow, int toCol)
{
    // ако началната клетка съвпада с крайната значи такъв път има
    if (fromRow == toRow && fromCol == toCol)
        return true;

    // Ако можем да стъпим надясно и има път от клетката вдясно от текущата и крайната, то значи има път и между текущата и крайната
    if (canMove(matrix, rows, cols, fromRow + 1, fromCol) && pathExistsHelper(matrix, rows, cols, fromRow + 1, fromCol, toRow, toCol))
    {
        return true;
    }

    // Ако можем да стъпим надолу и има път от клетката под от текущата и крайната, то значи има път и между текущата и крайната
    if (canMove(matrix, rows, cols, fromRow, fromCol + 1) && pathExistsHelper(matrix, rows, cols, fromRow, fromCol + 1, toRow, toCol))
    {
        return true;
    }

    // Ако можем да стъпим по диагонал и има път от клетката по диагонал от текущата и крайната, то значи има път и между текущата и крайната
    if (canMove(matrix, rows, cols, fromRow + 1, fromCol + 1) && pathExistsHelper(matrix, rows, cols, fromRow + 1, fromCol + 1, toRow, toCol))
    {
        return true;
    }

    return false;
}

bool pathExists(bool matrix[100][100], int rows, int cols)
{
    return pathExistsHelper(matrix, rows, cols, 0, 0, rows - 1, cols - 1);
}

int main()
{
    bool labyrinth[100][100] = {{1, 0, 0, 0},
                                {1, 1, 1, 1},
                                {0, 1, 0, 1},
                                {0, 1, 0, 1}};

    std::cout << pathExists(labyrinth, 4, 4);

    return 0;
}