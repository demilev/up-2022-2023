#include <iostream>

/*
    Напишете функция, която приема указател към първия и последен елемент на масив от цели числа
    и която връща указател към най-големия елемент в масива.
*/

int *maxElement(int *start, int *end)
{
    int *candidate = start;

    // Малко по-различен начин за обхождане на масив. Местим началния указател, докато не подминем крайния.
    while (start <= end)
    {

        // На всяка стъпка проверяваме дали текущият елемент е по-голям от максималния елемент досега.
        if (*start > *candidate)
            candidate = start;

        start++;
    }

    return candidate;
}

int main()
{
    int arr[500];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // arr - сочи към първия елемент на масива
    // arr + 1 сочи към втория елемент на масива
    // arr + 2 сочи към третия елемент на масива
    // ...
    // arr + (n - 1) сочи към n-ия и последен елемент на масива
    int *maxElementPtr = maxElement(arr, arr + (n - 1));

    std::cout << *maxElementPtr;

    return 0;
}