#include <iostream>

/*
    Да се напише функция `void capitalizeChars (char* word)`, която приема указател към `char` (указател към първия елемент на символен низ)
    и която променя всички малки букви в главни. Не използвайте синтаксис за достъп по индекс `word[i]`.
*/

// Не забравяме да пишем функции, винаги когато имаме възможност, защото това прави програмата ни в пъти по-добра.
bool isLower(char x)
{
    return x >= 'a' && x <= 'z';
}

char toUpper(char x)
{
    return x + ('A' - 'a');
}

// Стандартно решение, което приема масив
void capitalizeCharsArr(char word[])
{
    int i = 0;
    while(word[i] != 0)
    {
        if (isLower(word[i]))
            word[i] = toUpper(word[i]);
        i++;
    }
}

// Абослютно аналогично решение, което работи с указател
void capitalizeChars(char *word)
{
    int i = 0;
    while(*(word + i))
    {
        if (isLower(*(word + i)))
            *(word + i) = toUpper(*(word + i));
        i++;
    }
}

int main()
{
    char arr[] = "abcDeF";

    capitalizeChars(arr);

    std::cout << arr << std::endl;

    return 0;
}