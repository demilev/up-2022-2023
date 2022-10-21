#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 10;
    int b = 5;
    
    if (a = b)
    {
        std::cout << "a and b are equal" << std::endl;
    }
    else
    {
        std::cout << "a and b are not equal" << std::endl;
    }

    return 0;
}