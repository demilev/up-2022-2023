#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 5;
    int b = 2;
    int c = 10;
    int d = 15;
    
    std::cout << "a + b * c + d = " << a + b * c + d << std::endl;
    std::cout << "a * b * (c + d) = " << a * b * (c + d) << std::endl;

    return 0;
}