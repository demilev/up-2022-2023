#include <iostream>
#include <cmath> // Добавяме нова библиотека(нов header file), която съдържа набор от математически функции.

/*
    Да се напише програма, която приема четири цифрено число и проверя дали цифрите му са сортирани във възходящ ред.
*/
int main()
{

    double x1, y1, x2, y2, x3, y3;
    std::cout << "Please input x1: ";
    std::cin >> x1;

    std::cout << "Please input y1: ";
    std::cin >> y1;

    std::cout << "Please input x2: ";
    std::cin >> x2;

    std::cout << "Please input y2: ";
    std::cin >> y2;

    std::cout << "Please input x3: ";
    std::cin >> x3;

    std::cout << "Please input y3: ";
    std::cin >> y3;

    // Изчисляване на дължините на страните, използвайки формула за дължина на отсечка
    // между две точки в координатнат система.
    // Използваме две нови функции от стандартната библиотека. Забележете,
    // че те се използват по различен начин от операторите.
    // std::sqrt(number) и std::pow(base, exponent)
    double a = std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
    double b = std::sqrt(std::pow((x3 - x1), 2) + std::pow((y3 - y1), 2));
    double c = std::sqrt(std::pow((x2 - x3), 2) + std::pow((y2 - y3), 2));

    double p = (a + b + c) / 2; // Намираме полупериметъра, за да можем после да сметнем лицето по Херонова формула.
    double area = std::sqrt(p * (p - a) * (p - b) * (p - c));
    double height;

    if (a >= b && a >= c)
    {
        height = 2 * area / a;
    }
    else if (b >= a && b >= c)
    {
        height = 2 * area / b;
    }
    else if (c >= a && c >= b)
    {
        height = 2 * area / c;
    }

    std::cout << "The height is: " << height << std::endl;

    return 0;
}