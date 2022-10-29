#include <iostream>

/*
    Напишете програма, която по въведени две положителни числа проверява дали сумата на цифрите им съвпада.
*/

// Два пъти в програмата ще смятаме сумата на цифрите на дадено число,
// затова изнасяаме тази операция във функция. Веднъж имайки тази фунцкия,
// можем да я позлваме всеки път, когато искаме да намерим сумата на цифрите
// на произволно число.
int sumOfDigits(int x)
{
    int sumOfDigitsX = 0; // тази променлива ще пази сумата на цифрите
    while (x > 0)
    {
        sumOfDigitsX += x % 10; // добавяме текущата последна цифра към сумата
        x = x / 10;             // махаме текущата последната цифра
    }
    return sumOfDigitsX;
}

int main()
{

    int x = 0, y = 0;
    std::cin >> x >> y;

    int sumOfDigitsX = sumOfDigits(x);
    int sumOfDigitsY = sumOfDigits(y);

    // Използваме тернарен оператор `condition ? expression_true : expression_false`
    std::cout << ((sumOfDigitsX == sumOfDigitsY) ? "equal sum of digits" : "sum of digits are not equal") << std::endl;

    return 0;
}