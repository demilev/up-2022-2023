#include <iostream>

/*
    Да се напише функция void trim(char original[], char trimmed[]), която копира original в trimmed без всички space-ове в началото и края на низа.
*/

// Ще ползваме функцията, която написахме в Зад. 6. Именно за това са функциите - когато решим един проблем, можем да ползваме решението винаги когато срещнем този проблем.
void substring(char source[], int beginIndex, int endIndex, char target[])
{
    int i = 0;
    while (beginIndex < endIndex)
    {
        target[i++] = source[beginIndex++];
    }
    target[i] = 0;
}

// Идеята е следната - ще вземем първия и последния индекс, на който има елемент, който е различен от space.
// След това ще извикаме функцията substring, за да вземем всички елементи между тези два индекса.
void trim(char original[], char trimmed[])
{
    int length = strlen(original);

    int firstNoneSpaceIndex = 0;
    int lastNoneSpaceIndex = length - 1;

    while (original[firstNoneSpaceIndex] == ' ')
    {
        firstNoneSpaceIndex++;
    }

    while (original[lastNoneSpaceIndex] == ' ')
    {
        lastNoneSpaceIndex--;
    }

    substring(original, firstNoneSpaceIndex, lastNoneSpaceIndex, trimmed);
}

int main()
{
    char arr[100] = "   hello world!  ";
    char trimmedArr[100];

    trim(arr, trimmedArr);

    std::cout << strlen(trimmedArr) << std::endl;
    std::cout << trimmedArr << std::endl;

    return 0;
}