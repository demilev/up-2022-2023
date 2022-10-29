#include <iostream>
#include <cmath>

/*
   Напишете функция `void printInBinary(int number)`, която отпечатва представянето на числото number в двоична бройна система.
*/

void printBinary(int number)
{
    // Ще се изхитрим и ще конвертираме нашето оригинално число в друго такова, което има само цифрите 1 и 0.
    int result = 0;
    // Тази променлива ще пази позицията на текущата цифра в двоичен вид, която трябва да изчислим.
    int digitIndex = 0;

    while (number >= 1)
    {
        int powerOfTen = std::pow(10, digitIndex);
        result += (number % 2) * powerOfTen;
        number /= 2;
        digitIndex++;
    }

    std::cout << result << std::endl;
}

// Решение с рекурсия.
// Досега видяхме, че дадена функция може да вика друга функция.
// Но нищо не пречи една функция да извика себе си. Това се нарича рекурсия.
// Повече за това след някоя друга седмица.
void printBinaryRecursive(int number)
{
    if (number <= 1)
    {
        std::cout << number;
        return;
    }

    printBinaryRecursive(number / 2);
    std::cout << number % 2;
}

int main()
{
    printBinary(38);
    printBinaryRecursive(38);
}