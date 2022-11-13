#include <iostream>

/*
    Да се напише булева функция:
        - която проверява дали даден символен низ започва с друг символен низ
        - която проверява дали даден символен низ завършва с друг символен низ
*/

bool startsWith(char search[], char find[])
{
    int searchLength = strlen(search);
    int findLength = strlen(find);

    // Ако дължината на втория е по-голяма от дължината на първия, очевидно първия не започва с втория.
    if (findLength > searchLength)
        return false;

    // Ако изпълнението на програмата е стигнало до тук, то значи със сигурност findLength <= searchLength.
    // Това означава, че спокойно можем да обходим всички елементи на двата низа до индекс findLength -1.
    for (int i = 0; i < findLength; i++)
    {
        // Ако в някакъв момент намерим разминаване, значи search не започва със find
        if (search[i] != find[i])
            return false;
    }

    // Ако сме стигнали до тук, значи в нито един момент не е имало разминаване и search започва с find.
    return true;
}

bool endsWith(char search[], char find[])
{
    int searchLength = strlen(search);
    int findLength = strlen(find);

    // Ако дължината на втория е по-голяма от дължината на първия, очевидно първия не завършва с втория.
    if (findLength > searchLength)
        return false;

    // Абсолютно същите разсъждения като в предната функция, но този път ни трябва малко гимнастика с индексите при обхождането.
    for (int i = 0; i < findLength; i++)
    {

        // Независимо как обхождаме масива, винаги трябва да си задаваме въпроса дали индексът, който ще достъпваме, е в интервала [0, length - 1]
        int searchIndex = i + (searchLength - findLength);
        if (search[searchIndex] != find[i])
            return false;
    }

    return true;
}

int main()
{
    char search[] = "Hello world!";

    char prefix1[] = "Hello";
    char prefix2[] = "hello";
    char prefix3[] = "Hello world! How are you?";

    char suffix1[] = "world!";
    char suffix2[] = "world?";
    char suffix3[] = "world";
    char suffix4[] = "Hi! Hello world!?";

    std::cout << startsWith(search, prefix1) << std::endl;
    std::cout << startsWith(search, prefix2) << std::endl;
    std::cout << startsWith(search, prefix3) << std::endl;

    std::cout << endsWith(search, suffix1) << std::endl;
    std::cout << endsWith(search, suffix2) << std::endl;
    std::cout << endsWith(search, suffix3) << std::endl;
    std::cout << endsWith(search, suffix4) << std::endl;

    return 0;
}