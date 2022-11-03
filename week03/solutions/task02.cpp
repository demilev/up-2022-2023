#include <iostream>

/*
    Напишете програма, която при въведено естествено число n
    намира сумата на квадратите на всички числа от 1 до n (вкл.)
*/
int main()
{

    int n = 1, sum = 0;
    std::cin >> n;

    // Итерираме по всички числа от 1 до n
    for (int i = 1; i <= n; i++)
    {   
        // Добавяме квадрата на текущото число към променлива, която акумилира сумата.
        // Променливата sum е дефинирина извън цикъла, защото променливи, които се дефинират
        // в цикъла, биват унищожени на края на всяко изпълнение на цикъла.
        sum += i * i;
    }

    std::cout << sum << std::endl;

    return 0;
}