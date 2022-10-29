#include <iostream>

/*
    Да се напишат няколко прости функции:
    * `int absolute(int x)`, която връща абсолютната стойност на x ( т.е |x| ).
    * `bool isEven(int x)`, която връща дали числото x е четно
    * `char toLower(char sym)`, която връща малка буква по подадена главна такава
    * `void printAll(int from, int until)`, която отпечатва на екрана всички числа от `from` до `to`
*/

int absolute(int x)
{
    if (x > 0)
        // Ако x е повече от 0, директно го връщаме и приключваме изпълението на функцията
        return x;
    return -x;
}

bool isEven(int x)
{
    return x % 2 == 0; // Пример, че можем да върнем резултат от израз
}

char toLower(char sym)
{
    if (sym >= 'A' && sym <= 'Z')
    {
        return sym + 32;
    }
    return sym;
}

void printAll(int from, int until)
{
    // Пример за функция без резултат.
    for (int i = from; i < until; i++)
        std::cout << i << " ";
    return;
}

int main()
{
    // При извикаване на функция, програмата продължава изпълението
    // от първата инструкция в тялото на функцията.
    std::cout << absolute(5) << std::endl;
    // Когато приключи изпълението на функцията, програмата продължава
    // оттам откъдето е спряла, за да извика функцията.

    std::cout << absolute(-5) << std::endl;

    std::cout << isEven(2) << std::endl;
    std::cout << isEven(1) << std::endl;

    std::cout << toLower('a') << std::endl;
    std::cout << toLower('B') << std::endl;

    // printAll е функция без резултат.
    // Не се опитваме да я присвоим на променлива, не се опитваме да я ползваме в израз,
    // не се опитваме да я отпечатаме на екрана. Просто я извикаваме.
    printAll(5, 10);
}