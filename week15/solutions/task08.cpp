#include <iostream>

/*
    Напишете рекурсивна функция, която отпечатва декодиран символен низ. Пример:

    ```
    вход: 3а2bcd2a
    изход: aaabbcdaa
    ```
*/

// Помощна функция, която проверява дали даден символ е цифра
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

// Помощна функция, която превръща даден символ в цифра
int toDigit(char c)
{
    return c - '0';
}

void printDecoded(char *str)
{
    // Празният низ, както винаги, е дъното на рекурсията
    if (*str == 0)
    {
        std::cout << std::endl;
        return;
    }

    // Ако текущият символ е цифра, трябва да отпечатаме следващия толкова на брой пъти.
    // Помислете как функцията може да поддържа низове от вида "12a355b4cd"
    if (isDigit(*str))
    {
        int digit = toDigit(*str);
        for (int i = 0; i < digit; i++)
        {
            std::cout << *(str + 1);
        }

        // Продължаваме от по-следващия символ
        printDecoded(str + 2);
    }
    else
    {
        // В противен случай печатаме текущия символ и продължаваме напред
        std::cout << *str;
        printDecoded(str + 1);
    }
}

int main()
{
    char str[] = "3a2bcd2a";
    printDecoded(str);
    return 0;
}