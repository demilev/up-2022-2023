#include <iostream>

/*
    Напишете функция `char* concat(char* first, char* second)`,
    която връща указател към новосъздаден (динамично) символен низ, който представлява конкатенацията на `first` и `second`.
*/

char *concat(char *first, char *second)
{
    int firstSize = strlen(first);
    int secondSize = strlen(second);

    // Когато заделяме динамично памет, можем да кажем точно колко памет ни трябва.
    // В случая знаем, че резултатът ще съдържа всички символи на първия и втория низ и не забравяме, че накрая ще трябва
    // да сложим и терминираща нула.
    char *result = new char[firstSize + secondSize + 1];

    int index = 0;

    // Първо копираме всички елементи на първия низ
    for (int i = 0; i < firstSize; i++)
    {
        result[index] = first[i];
        index++;
    }

    // След това копираме всички елементи на втория
    for (int i = 0; i < secondSize; i++)
    {
        result[index] = second[i];
        index++;
    }

    // Накрая слагаме терминиращата нула
    result[index] = 0;

    return result;
}

int main()
{
    char arr1[] = "Hello ";
    char arr2[] = "World!";

    char *result = concat(arr1, arr2);

    std::cout << result << std::endl;

    // Не забравяме, че винаги трябва да зачистим паметта, която сме заделили динамично.
    delete[] result;

    return 0;
}