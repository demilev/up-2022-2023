#include <iostream>

int* f()
{
    int *x;
    x = new int;

    return x;
}

int main()
{
    int *x = f();

    int n;
    std::cin >> n;

    int *arr = new int[n];

    int arr1[100];

    return 0;
}