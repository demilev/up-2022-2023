#include <iostream>

/*
    Напишете програма, която по въведенa буква, отпечатва на екрана дали буквата е главна или малка.
*/
int main()
{

    char letter;

    std::cin >> letter;

    // Симовлите(както и всяко друго нещо) в паметта са просто поредица от битове.
    // Т.е. те също са просто числа. Кодировката между символ и число е изразена
    // в ASCII таблицата.
    // Бърза справка с нея показва, че главна буква се кодира с числото 65,
    // а голяма буква Z се кодира с числото 90.
    if (letter >= 65 && letter <= 90)
    {
        std::cout << "The input symbol is an upper letter" << std::endl;
    }
    // Малките букви са между 97 и 122
    else if (letter >= 97 && letter <= 122)
    {
        std::cout << "The input symbol is a lower letter" << std::endl;
    }
    else
    {
        std::cout << "The input symbol is not a letter" << std::endl;
    }

    return 0;
}