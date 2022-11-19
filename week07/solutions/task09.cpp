#include <iostream>

/*
    Имплементирайте играта tic-tac-toe(3х3). Нека на всеки ход програмата отпечатва текущото състояние на дъската
    и да кара текущия играч да въведе следващия си ход. Играта се играе докато някой не спечели или на дъската не останат празни клетки.
*/

/*
    Ще моделираме дъската като матрица 3х3 от символи. Всеки елемент на матрицата ще държи символа на играча,
    който е играл хода си на това поле или 0, ако полето все още не е изиграно.
*/

// Функция, която инициализира дъската с терминиращи нули.
void initialiseBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

// Фунцкия, която проверява дали има победител.
bool checkWinner(char board[3][3])
{

    // Проверка за победител по редовете
    for (int row = 0; row < 3; row++)
    {
        char move = board[row][0];
        bool allEqual = true;
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] != move)
            {
                allEqual = false;
                break;
            }
        }
        if (allEqual && move != 0)
            return true;
    }

    // Проверка за победител по колоните
    for (int col = 0; col < 3; col++)
    {
        char move = board[0][col];
        bool allEqual = true;
        for (int row = 0; row < 3; row++)
        {
            if (board[row][col] != move)
            {
                allEqual = false;
                break;
            }
        }
        if (allEqual && move != 0)
            return true;
    }

    // Проверка за победител по главния диагонал
    bool mainDiagonalAllEqual = true;
    char mainDiagonalMove = board[0][0];
    for (int i = 0; i < 3; i++)
    {

        if (board[i][i] != mainDiagonalMove)
        {
            mainDiagonalAllEqual = false;
            break;
        }
    }
    if (mainDiagonalAllEqual && mainDiagonalMove != 0)
    {
        return true;
    }

    // Проверка за победител по вторичния диагонал
    bool secondaryDiagonalAllEqual = true;
    char secondaryDiagonalMove = board[0][2];
    for (int i = 0; i < 3; i++)
    {
        if (board[i][3 - i - 1] != secondaryDiagonalMove)
        {
            secondaryDiagonalAllEqual = false;
            break;
        }
    }
    if (secondaryDiagonalAllEqual && secondaryDiagonalMove != 0)
    {
        return true;
    }

    return false;
}

// Функция, която проверяв дали дъската е запълнена. Това би означавало, че резултатът е равен.
bool boardFull(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return false;
    return true;
}

// Функция, която кара текущия играч да изиграе хода си. Ако играчът въведе невалиден ход,
// го караме да въведе хода си наново и така докато не въведе валиден ход.
void applyMove(char board[3][3], int player, char playerMove)
{
    int i, j;
    std::cout << "Player " << player << " move(row & col): ";
    std::cin >> i >> j;

    while (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j])
    {
        std::cout << "Invalid move! Try again!" << std::endl;
        std::cout << "Player " << player << " move: ";
        std::cin >> i >> j;
    }

    board[i][j] = playerMove;
}

// Фунцкия, която връща следващия играч, който е на ход.
int nextPlayer(int player)
{
    return player % 2 + 1;
}

// Функция, която отпечатва текущото състояние на дъската.
void printBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board[i][j])
                std::cout << board[i][j] << " ";
            else
                std::cout << "_"
                          << " ";
        std::cout << std::endl;
    }
}

int main()
{
    char playerChars[2] = {'x', 'o'};

    char board[3][3];
    initialiseBoard(board);

    int player = 1;
    bool hasWinner = false;

    printBoard(board);

    // Играем, докато няма победител и докато дъската не е запълнена
    while (!hasWinner && !boardFull(board))
    {
        // Изиграваме хода на текущия играч
        applyMove(board, player, playerChars[player - 1]);

        // Преминаваме към следващия играч
        player = nextPlayer(player);

        // Отпечатваме състоянието на дъската
        printBoard(board);

        // Правим проверка за победител
        hasWinner = checkWinner(board);
    }

    if (hasWinner)
    {
        std::cout << "The winner is player " << nextPlayer(player) << "!" << std::endl;
    }
    else
    {
        std::cout << "It's a tie!" << std::endl;
    }
    return 0;
}