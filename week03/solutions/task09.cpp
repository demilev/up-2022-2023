#include <iostream>
#include <cmath>

/*
    Напишете програма, която проверява дали едно число е автоморфно.
    Дадено число е автоморфно, ако квадратът му завършва на него самото.
*/
int main()
{

    int n = 0;
    std::cin >> n;

    /*
        Вече няколко пъти видяхме, че за да вземем последната цифра на дадено число
        използваме % 10. Ако искаме последните две цифри, тогава трябва да видим
        остатък при деление на 100. Ако искаме последните n цифри, тогава трябва да видим
        остатък при деление на 10 ^ n.
    */

    // Преброяваме цифрите на нашето оригинално число
    int countOfDigits = 0;
    int copyOfN = n; // Създаваме копие на числото, за да не загубим оригиналната му стойност.
    while (copyOfN > 0)
    {
        countOfDigits++;
        copyOfN /= 10;
    }

    // Вземаме последните цифри на квадрата на оригиналното число
    int square = std::pow(n, 2);
    int powOfTen = std::pow(10, countOfDigits);
    int remainder = square % powOfTen;

    // Сравняваме
    if (remainder == n)
        std::cout << "The number is automorphic" << std::endl;
    else
        std::cout << "The number is not automorphic" << std::endl;

    return 0;
}