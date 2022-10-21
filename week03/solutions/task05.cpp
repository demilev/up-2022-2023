#include <iostream>

/*
    Напишете програма, която изчислява двойния факториел на въведено от потребителя число.
*/
int main()
{

    int n;
    std::cin >> n;
    int result = 1;
    int factor;

    // Ако числото е четно, започваме от 2.
    if (n % 2 == 0)
        factor = 2;
    // В противен случай от 1.
    else
        factor = 1;

    // Обхождаме всички числа до n през 2
    while (factor <= n)
    {
        result *= factor;
        factor += 2;
    }

    std::cout << "The double factoriel of " << n << " is: " << result;
    return 0;
}