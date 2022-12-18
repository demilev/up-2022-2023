#include <iostream>

/*
    Напишете програма, която намира решението на судоку.
*/

// Помощна функция за печатане на судокуто
void print(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

// Функция, която проверява дали числото num може да бъде записано в клетка (row, col)
bool isSafe(int grid[9][9], int row, int col, int num)
{
    // Проверка дали това число вече съществува на реда
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num)
            return false;

    // Проверка дали това число вече съществува в колоната
    for (int x = 0; x < 9; x++)
        if (grid[x][col] == num)
            return false;

    // Проверка дали това число вече съществува в 3х3 квадратчето му
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Функция, която се опитва да реши судоку, приемайки,
// че всички клетки с ред < row или ред = row и колона < col са вече попълнени
bool solveSudoku(int grid[9][9], int row, int col)
{
    // Ако всичко вече е попълнено, значи судокуто е решено
    if (row == 8 && col == 9)
        return true;

    // Ако сме стигнали края на текущия ред, минаваме на следващия
    if (col == 9)
    {
        row++;
        col = 0;
    }

    // Ако текущата клетка вече е попълнена, преминаваме на следващата
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    // Ако текущата клетка не е попълнена,
    // пробваме да запишем всяка една стойност и да дорешим останалата част от судокуто.
    for (int num = 1; num <= 9; num++)
    {

        // Все пак проверяваме дали можем да запишем num в клетка (row, col)
        if (isSafe(grid, row, col, num))
        {
            // Записваме го
            grid[row][col] = num;

            // Пробваме да дорешим судокуто
            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        // Backtracking! - ако сме стигнали дотук, значи не сме успяли да решим судокуто,
        // затова зануляваме клетката и продължаваме да опитваме
        grid[row][col] = 0;
    }

    return false;
}

int main()
{
    // С 0 бележим празната клетка
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        std::cout << "Решение не съществува!" << std::endl;

    return 0;
}
