#include <iostream>

/*
    Напишете програма, в която по въведено число се извежда името на месеца, който съответства на това число.
*/

int main()
{

    int month;

    std::cin >> month;

    /*
        Използваме условната конструкция switch, за да избегнем писането на много if-ове.

        Ако стойността на израза в switch-а съвпадне с тази от някой case,
        то тогава изпълнението на програмата продължава от там.

        Ако стойността на израза в switch-а не съвпадне с тази от някой case,
        то тогава изпълнението на програмата продължава от този case, който е
        с етикет default. Ако такъв няма, то тогава не се изпълнява нищо и програмата
        продължава.
    */

    switch (month)
    {
    case 1:
        std::cout << "January" << std::endl;
        break; // Ключува дума 'brake'. Използваме я, за да приключим изпълнението на switch-а. Тествайте какво става, когато я няма.
    case 2:
        std::cout << "February" << std::endl;
        break;
    case 3:
        std::cout << "March" << std::endl;
        break;
    case 4:
        std::cout << "April" << std::endl;
        break;
    case 5:
        std::cout << "May" << std::endl;
        break;
    case 6:
        std::cout << "June" << std::endl;
        break;
    case 7:
        std::cout << "July" << std::endl;
        break;
    case 8:
        std::cout << "August" << std::endl;
        break;
    case 9:
        std::cout << "September" << std::endl;
        break;
    case 10:
        std::cout << "October" << std::endl;
        break;
    case 11:
        std::cout << "November" << std::endl;
        break;
    case 12:
        std::cout << "December" << std::endl;
        break;
    default:
        std::cout << "Invalid month number " << month << std::endl;
        break;
    }

    return 0;
}