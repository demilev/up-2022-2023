#include <iostream>

/*
   Да се напише функция, която сравнява дали две числа дават един и същ остатък при деление на 3-то число. 
   Трите числа да се подават като параметри на функцията.
*/

bool equalRemainder(int firstNumber, int secondNumber, int divider)
{
    return firstNumber % divider == secondNumber % divider;
}


int main()
{
    std::cout << equalRemainder(12, 7, 5) << std::endl;
}