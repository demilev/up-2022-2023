#include <iostream>
#include <fstream>

/*
    Напишете програма, която прочита съдържанието на текстов файл ред по ред и го печата на екрана. Приемете, че всеки ред е до 1024 символа.
*/

int main()
{
    std::ifstream file;

    file.open("task01.cpp"); // Отваряме файла

    char line[1024];

    // Оценява се на истина, ако нещо е прочетено и на лъжа, ако сме стигнали края на файла
    while (file.getline(line, 1024)) // Фунцията getline работи по същия начин, както std::cin.getline
    {
        std::cout << line << std::endl;
    }

    file.close(); // Затваряме файла

    return 0;
}