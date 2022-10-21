#include <iostream>

/*
    Напишете програма, която отпечатва всички делители на въведено число.
*/
int main()
{

    int n = 1;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            std::cout << i << std::endl;   
    }

    return 0;
}