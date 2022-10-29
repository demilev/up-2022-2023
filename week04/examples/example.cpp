#include <iostream>

void print(int a)
{
    std::cout << a;
}

int plus(int a, int b)
{   
    int c = a + b;
    a += b;
    print(a);

    return c;
}

int input()
{
    int x;
    std::cin >> x;
    return x;
}

int main() {
    int a = 3;
    std::cout << plus(a, 5) << std::endl;
    std::cout << a << std::endl;
    return 0;
}