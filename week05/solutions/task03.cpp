#include <iostream>

// Проста функция, която прави кодът ни по-четим.
bool isUpper(char x)
{
    return x >= 'A' && x <= 'Z';
}

int main()
{

    char arr[50];
    // За разлика от предните задачи, тук въвеждаме елементите на масива "наведнъж"(защото е символен низ).
    // С помощта на функцията getline, стойността на масива ще е всичко, което
    // въведем от клавиатурата до натискане на 'enter'(нов ред) или докато не въведем 49 символа.
    // Накрая на масива се слага терминиращата нула.
    std::cin.getline(arr, 50);

    // Вземаме първия елемент на масива и го подаваме като параметър на функция.
    if (isUpper(arr[0]))
        // За разлика от предните задачи, тук можем да отпечатаме елеменентите на масива "наведнъж"(защото е символен низ).
        // На екрана ще бъдат отпечатани всички елементи на масива до първата терминираща нула.
        std::cout << arr << std::endl;
    else
        std::cout << "The string does not start with an upper case letter!" << std::endl;

    return 0;
}