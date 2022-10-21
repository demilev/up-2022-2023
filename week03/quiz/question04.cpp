#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 20;
    
    if (a < 30)
    {
        std::cout << "a is less than 30" << std::endl;
    }

    if (a < 50)
    {
        std::cout << "a is less than 50" << std::endl;
    }
    else
    {
        std::cout << "a is more than 50" << std::endl;
    }

    return 0;
}