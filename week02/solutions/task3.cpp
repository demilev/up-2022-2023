#include <iostream>

/*
    Да се напише програма, която по въведени три числа проверя дали може да бъде образвуан триъгълник с дължини на страните тези три числа.
*/
int main()
{

    int a, b, c;

    std::cin >> a >> b >> c;

    // Въвеждаме три помощни променливи със смислени имена, за да подобрим четимостта на нашия код.
    bool inequalityA = b + c > a; // Оператор '+' е с по-висок приоритет от оператор '>'
    bool inequalityB = a + c > b;
    bool inequalityC = a + b > c;

    if (a < 0 || b < 0 || c < 0) // Виждаме свойство асоциотивност на оператора логичско или
    {
        std::cout << "Invalid input" << std::endl;
    }
    else
    {
        if (inequalityA && inequalityB && inequalityC) // Виждаме свойство асоциотивност на оператора логичско и
        {
            std::cout << a << ", " << b << " and " << c << " can form a triangle" << std::endl;
        }
        else
        {
            std::cout << a << ", " << b << " and " << c << " can't form a triangle" << std::endl;
        }
    }

    return 0;
}