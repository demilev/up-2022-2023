#include <iostream>

/*
    Напишете програма, която при въведен числов масив с размер n (0 <= n <= 20) извежда на екрана сумата на всички числа, които са на позиции в масива, кратни на 3.
*/
int main()
{

    int n;
    std::cin >> n;
    int arr[20];

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // Обикновено ще обхождаме всички елементи на масива,
    // но нищо не ни пречи и да "скачаме" на произволни места из него.
    for (int i = 0; i < n; i += 3)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}