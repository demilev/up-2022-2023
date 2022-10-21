#include <iostream>

/*
    Какво ще бъде изведено на екрана при изпълянване на следната програма?
*/

int main()
{

    int a = 42;
    
    if (a)
    {
        std::cout << "Correct answer!" << std::endl;
    }
    else
    {
        std::cout << "Incorrect answer!" << std::endl;
    }

    return 0;
}