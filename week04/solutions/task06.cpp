#include <iostream>
#include <cmath>

/*
   Напишете функция `void printAllSubNumbers(int number)`, която отпечатва всички числа, които се съдържат в number.
*/

/*
    Преизползваме всичко, което написахме за задача 5.
*/

int countDigits(int number)
{
    int count = 1;
    while (number > 9)
    {
        number = number / 10;
        count++;
    }
    return count;
}

bool endsWith(int find, int search)
{
    int numberOfDigits = countDigits(find);
    int powerOfTen = std::pow(10, numberOfDigits);

    int remainder = search % powerOfTen;

    return remainder == find;
}

bool isSubNumber(int find, int search)
{

    while (search >= find && search > 0)
    {
        if (endsWith(find, search))
        {
            return true;
        }
        search = search / 10;
    }

    return false;
}

// Единственото ново е тази функция, която изглежда много простичко след всичко което написахме досега
void printAllSubNumbers(int number)
{
    for (int i = 0; i <= number; i++)
    {
        if (isSubNumber(i, number))
        {
            std::cout << i << std::endl;
        }
    }
}

int main()
{
    printAllSubNumbers(305);
}