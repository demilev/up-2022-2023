#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 20;
    
    if (a % 2 == 0)
        std::cout << "a is even" << std::endl;
    else
        std::cout << "a is not even" << std::endl;
        std::cout << "a is odd" << std::endl;

    return 0;
}