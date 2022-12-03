#include <iostream>

/*
    Напишете рекурсивна функция, която приема символен низ и дължината му
    и която връща `true`, ако той е палиндром и `false` в противен случай.
*/

bool isPalindrome(char *word, int len)
{
    // Всеки символен низ с дължина под 2 символа е палиндром
    if (len < 2)
        return true;

    bool firstAndLastCharMatch = *word == *(word + len - 1);

    // Един символен низ е палиндром, ако първата му и последна буква съвпадат и ако низът между тях също е палиндром
    return firstAndLastCharMatch && isPalindrome(word + 1, len - 2);
}

int main()
{

    char palindrome[] = "abcdcba";
    char notPalindrome[] = "aXcdcba";

    std::cout << isPalindrome(palindrome, strlen(palindrome)) << std::endl;
    std::cout << isPalindrome(notPalindrome, strlen(notPalindrome)) << std::endl;

    return 0;
}