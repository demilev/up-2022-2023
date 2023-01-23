#include <iostream>

/*
    Напишете функция, която приема символен низ и връща указател към нов символен низ, който съдържа всички елементи на оригиналния низ,
    но всички съседни повторения на символ са премахнати.
*/

char *removeRepetitions(char *str)
{
    int size = strlen(str);
    // Може да ни трябва по-малко памет за резултата, но не пречи да заделим малко повече памет
    char *result = new char[size + 1];

    int index = 1;
    result[0] = str[0];
    // Обхождаме оригиналния низ
    for (int i = 1; i < size; i++)
    {
        // Ако текущият елемент е различен от предишния, го записваме в резултата
        if (str[i] != str[i - 1])
            result[index++] = str[i];
    }

    // Не забравяме да сложим терминираща нула накрая на резултата
    result[index] = 0;

    return result;
}

int main()
{

    char str[] = "AABBBCDDD";
    char *result = removeRepetitions(str);

    std::cout << result << std::endl;

    // Почистваме динамично заделената памет
    delete[] result;

    return 0;
}