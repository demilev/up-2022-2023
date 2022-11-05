#include <iostream>

/*
    Да се напише програма, която създава масив с максимален размер 20.
    Програмата да кара потребителя да въведе реалния размер n <= 20 и след това го кара да въведе първите n на брой елементи на масива и после ги отпечатва.
*/

int main()
{
    // Декларираме масив с елементи от тип int и размер 20.
    int arr[20];
    int n;
    std::cin >> n;

    // Правим проверка за коректност на входа, защото c++ не прави проверка дали елемнтът, който достъпваме е в границите на масива.
    // Т.е. нищо не ни пречи да напишем нещо от рода на arr[-5] или arr[234], но то ще доведе до недефинирано поведение.
    if (n > 0 && n <= 20)
    {
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];

        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";

        std::cout << std::endl;
    }
    else
    {
        std::cout << "Invaild innput size: " << n << ". The size must be in the range [0, 20]." << std::endl;
    }

    return 0;
}