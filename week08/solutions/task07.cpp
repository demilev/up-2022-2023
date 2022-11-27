#include <iostream>

/*
    Напишете функция `char* nextSentence(char* text)`,
    която връща указател към елемента след първото срещане на препинателния знак точка.
*/

char *findSentence(char *text)
{
    // Тук виждаме нова ключова дума - nullptr. nullptr е указател, който не сочи към нищо.
    if (text == nullptr)
        return nullptr;

    // Обхождаме масива, докато не стигнем до края или не стигне до точка.
    while (*text && *text != '.')
    {
        // Това е операция с указател. text++ <=> text = text + 1 <=> премести указателя една char кутийка напред
        text++;
    }

    // Ако не сме стигнали края на масива, значи сме стигнали точка и връщаме адреса след нея.
    if (*text)
        return text + 1;

    // В противен случай сме стигнали края на масива без да намерим точка и връщаме указател, който не сочи към нищо.
    return nullptr;
}

int main()
{

    char text[] = "Hello World.How are you?";

    std::cout << findSentence(text) << std::endl;

    return 0;
}