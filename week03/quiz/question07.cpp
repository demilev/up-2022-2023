#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int c = 10;
    
    switch (c)
    {
    case 5:
        std::cout << "c is 5" << std::endl;
        break;
    case 6:
        std::cout << "c is 6" << std::endl;
        break;
    default:
        std::cout << "c is something else" << std::endl;
        break;
    }

    return 0;
}