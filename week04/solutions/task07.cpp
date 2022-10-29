#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    Имплементирайте играта "Камък, Ножица, Хартия". За целта имплементирайте функции:
        * `int rps(char firstPlayerMove, char secondPlayerMove)`, която приема ходовете на двама играчи и връща -1, ако е спечелил първият играч, 0, ако е равенство и 1, ако е спечелил вторият играч.
          Приемете, че символ 'r' кодира камък, символ 'p' кодира хартия, символ 's' кодира ножица.
        * `char randomMove()`, която генерира произволен ход('r', 'p' или 's')
    Нека програмата приема за вход формата на играта, и на всеки рунд генерира произволен ход за компютъра и пита потребителя за неговия ход.
    Играта се играе, докато няма победител. На екрана се отпечатва крайният резултат.
*/

int rps(char firstPlayerMove, char secondPlayerMove)
{
    // Описваме всички възможности на ръка
    if (firstPlayerMove == secondPlayerMove)
        return 0;
    if (firstPlayerMove == 'r' && secondPlayerMove == 'p')
        return 1;
    if (firstPlayerMove == 'r' && secondPlayerMove == 's')
        return -1;
    if (firstPlayerMove == 'p' && secondPlayerMove == 's')
        return 1;
    if (firstPlayerMove == 'p' && secondPlayerMove == 'r')
        return -1;
    if (firstPlayerMove == 's' && secondPlayerMove == 'r')
        return 1;
    if (firstPlayerMove == 's' && secondPlayerMove == 'p')
        return -1;
    return 0;
}

char randomMove()
{
    // Генерираме си произволно число по познатия ни вече начин
    int randomNumber = rand() % 3;

    switch (randomNumber)
    {
    case 0:
        return 'r';
    case 1:
        return 'p';
    case 2:
        return 's';
    }

    return 0;
}

int main()
{
    std::srand(std::time(nullptr));

    int rounds;
    std::cout << "Please input the maximum number of rounds: ";
    std::cin >> rounds;

    // Изчисляваме точките, които са необходими, за да спечелиш играта.
    int pointsToWin = rounds / 2 + 1;
    // Две променливи, с които ще пазим резултата на играчите.
    int playerScore = 0, computerScore = 0;
    // Променлива, която ще брои на кой рунд сме.
    int round = 1;

    // Играем, докато някой не спечели.
    while (playerScore < pointsToWin && computerScore < pointsToWin)
    {
        // Въвеждаме нашия ход.
        char playerMove;
        std::cout << "Please input move " << round << ": ";
        std::cin >> playerMove;

        // Генерираме ход за компютъра.
        char computerMove = randomMove();

        // Обновяваме резултатите
        int result = rps(playerMove, computerMove);
        if (result < 0)
            playerScore++;
        if (result > 0)
            computerScore++;

        std::cout << "Computer: " << computerMove << ", Player: " << playerMove << " - Result " << computerScore << " - " << playerScore << std::endl;
        round++;
    }

    if (playerScore > computerScore)
        std::cout << "The result is " << computerScore << " - " << playerScore << " You are the winner!" << std::endl;
    else
        std::cout << "The result is " << computerScore << " - " << playerScore << " You lost!" << std::endl;

    return 0;
}