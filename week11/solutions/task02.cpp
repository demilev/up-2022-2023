#include <iostream>

/*
    Напишете функция, която прима матрица NxМ (N,М<=100), която е съставена само от 0 и 1
    и която пребровява броя на пътищата от клетката с координати (0, 0) до клетка с координати (N - 1, M - 1)
    съставен само от 1ици(движението от една клетка в друга става по вертикал и по хоризонтал).
*/

/* Ще опростим задачата и ще работим с матрица с фиксиран размер 9х9 */

// Помощна функция, която ще ни казва дали можем да продължим с клетка (i, j)
bool canMove(bool matrix[9][9], int i, int j)
{
    if (i < 0 || i >= 9 || j < 0 || j >= 9)
        return false;
    return matrix[i][j];
}

// Помощна функция, която ще връща броя на пътищата между клетка с координати (fromRow, fromCol) и клетка с координати (toRow, toCol)
int numberOfPathsHelper(
    bool matrix[9][9],
    int fromRow,
    int fromCol,
    int toRow,
    int toCol,
    bool visited[9][9])
{
    // Ако началната клетка съвпада с крайната, значи има един тривиален път
    if (fromRow == toRow && fromCol == toCol)
    {
        return 1;
    }

    // Ако текущата клетка вече е била посетена, значи сме зациклили и връщаме нула
    if (visited[fromRow][fromCol])
    {
        return 0;
    }

    // Посещаваме текущата клетка
    visited[fromRow][fromCol] = true;

    int paths = 0;

    // Броят на пътищата от текущата клетка е сумата от броя на пътищата на съседните й клетки.

    // Ако можем да стъпим надолу, добавяме броя на всички пътища от долната клетка до крайната
    if (canMove(matrix, fromRow + 1, fromCol))
    {
        paths += numberOfPathsHelper(matrix, fromRow + 1, fromCol, toRow, toCol, visited);
    }

    // Ако можем да стъпим нагоре, добавяме броя на всички пътища от горната клетка до крайната
    if (canMove(matrix, fromRow - 1, fromCol))
    {
        paths += numberOfPathsHelper(matrix, fromRow - 1, fromCol, toRow, toCol, visited);
    }

    // Ако можем да стъпим надясно, добавяме броя на всички пътища от дясната клетка до крайната
    if (canMove(matrix, fromRow, fromCol + 1))
    {
        paths += numberOfPathsHelper(matrix, fromRow, fromCol + 1, toRow, toCol, visited);
    }

    // Ако можем да стъпим наляво, добавяме броя на всички пътища от лявата клетка до крайната
    if (canMove(matrix, fromRow, fromCol - 1))
    {
        paths += numberOfPathsHelper(matrix, fromRow, fromCol - 1, toRow, toCol, visited);
    }

    // Backtracking! - отбелязваме текущата клетка като непосетена
    visited[fromRow][fromCol] = false;

    return paths;
}

int numberOfPaths(bool matrix[9][9])
{
    bool visited[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            visited[i][j] = false;

    return numberOfPathsHelper(matrix, 0, 0, 8, 8, visited);
}

int main()
{
    bool labyrinth[9][9] = {{1, 0, 0, 0, 1, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {0, 1, 0, 0, 1, 0, 0, 0, 1},
                            {0, 1, 0, 0, 1, 0, 0, 0, 1},
                            {0, 1, 0, 0, 1, 1, 1, 0, 1},
                            {0, 1, 0, 0, 1, 0, 1, 0, 1},
                            {0, 1, 0, 0, 1, 1, 1, 0, 1},
                            {0, 1, 0, 0, 0, 1, 0, 0, 1},
                            {0, 1, 1, 1, 1, 1, 1, 1, 1}};

    std::cout << numberOfPaths(labyrinth);

    return 0;
}