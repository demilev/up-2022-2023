#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 10;
    int b = 5;

    if (a % 2 == 0)
    {
        if (b % 2 == 1)
        {   
            std::cout << "a is even, b is odd" << std::endl;
        }
        else
        {
            std::cout << "a is even, b is even" << std::endl;
        }
    }
    else
    {
        if (b % 2 == 1)
        {
            std::cout << "a is odd, b is odd" << std::endl;
        }
        else
        {
            std::cout << "a is odd, b is even" << std::endl;
        }
    }

    return 0;
}