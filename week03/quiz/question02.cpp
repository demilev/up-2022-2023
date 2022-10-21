#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 12345;
    char c = a;
    int aCopy = c;

    if (a == aCopy)
    {
        std::cout << "a is equal to aCopy" << std::endl;
    }
    else
    {
        std::cout << "a is not equal to aCopy" << std::endl;
    }


    return 0;
}