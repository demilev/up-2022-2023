#include <iostream>

/*
    Напишете програма, която по въведени две положителни числа проверява дали сумата на цифрите им съвпада.
*/
int main()
{

    int x = 0, y = 0;
    std::cin >> x >> y;

    int sumOfDigitsX = 0; // тази променлива ще пази сумата на цифрите
	while (x > 0) {
		sumOfDigitsX += x % 10; // добавяме текущата последна цифра към сумата
		x = x / 10; // махаме текущата последната цифра
	}

    // Същото за y(дали няма начин да не трябва да копираме кода?)
    int sumOfDigitsY = 0;
	while (y > 0) {
		sumOfDigitsY += y % 10;
		y = y / 10;
	}

    // Използваме тернарен оператор `condition ? expression_true : expression_false`
    std::cout << ((sumOfDigitsX == sumOfDigitsY) ? "equal sum of digits" : "sum of digits are not equal") << std::endl; 

    return 0;
}