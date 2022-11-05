#include <iostream>

/*
    Да се напише програма, която кара потребителя да въведе от клавиатурата символен низ с размер n <= 50 и да отпечатва на екрана
    дали е въведено съобщително, въпросително, възклицателно изречение или не е въведено изречение.
*/

int main()
{

    char sentence[50];
    std::cin.getline(sentence, 50);

    // Искаме да видим какъв е последният елемент на масива.
    // За целта ще намерим колко е дължината му и ще достъпим елемента
    // на индекс `дължина - 1`. За целта ще се възползваме от факта, че
    // знаем, че низът завършва с терминираща нука.
    int length = 0;
    while (sentence[length] != 0)
    {
        length++;
    }

    // switch оператор по последния елемент в низа
    switch (sentence[length - 1])
    {
    case '.':
        std::cout << "'" << sentence << "' is declarative. " << std::endl;
        break;
    case '?':
        std::cout << "'" << sentence << "' is interrogative. " << std::endl;
        break;
    case '!':
        std::cout << "'" << sentence << "' is exclamatory/imperative. " << std::endl;
        break;
    default:
        std::cout << "'" << sentence << "' is not a sentence. " << std::endl;
        break;
    }

    return 0;
}