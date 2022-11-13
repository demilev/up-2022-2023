#include <iostream>

/*
    Да се напише функция void substring(char source[], int beginIndex, int endIndex, char target[]), която копира всички елементи на source между позиция beginIndex и endIndex в target.
*/

void substring(char source[], int beginIndex, int endIndex, char target[])
{
    int i = 0;
    // Не обхождаме целия низ source, а само елементите му между beginIndex и endIndex.
    while (beginIndex < endIndex)
    {
        target[i++] = source[beginIndex++];
    }

    // Важно! Не забравяме да сложим терминираща нула накрая.
    target[i] = 0;
}

int main()
{
    char arr[100] = "hello world!";
    char subArr[100];

    substring(arr, 6, 11, subArr);

    std::cout << strlen(subArr) << std::endl;
    std::cout << subArr << std::endl;

    return 0;
}