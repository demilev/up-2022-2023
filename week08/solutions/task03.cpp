#include <iostream>
/*
    Напишете функция `void swap(тип а , тип b)`, която приема две числа и разменя техните стойности
    (стойностите трябва да продължат да бъдат разменени и след приключването на функцията).
*/

// Абсолютно същите разсъждения, както в предната задача, важат и в тази.

void swapNotWorking(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swapPtr(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 4;
    int b = 5;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapPtr(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}