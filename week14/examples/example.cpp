#include <iostream>
#include <fstream>

struct Student
{
    int fn;
    char name[20];
    double grade;
};

int main()
{
    int i = 5;

    // Отваряме текстов файл за писане
    std::ofstream txtOutFile;
    txtOutFile.open("example.txt");

    // Пишем по абослютно същия начин, по който бихме писали на стандартния изход.
    // Всичко което знаем досега си важи.
    txtOutFile << i;

    // Затваряме файла, когато сме приключи с ползването му
    txtOutFile.close();

    // Отваряме текстов файл за четене
    std::ifstream txtInFile;
    txtInFile.open("example.txt");

    // Четем по абослютно същия начин, по който бихме чели от стандартния вход.
    // Всичко което знаем досега си важи.
    txtInFile >> i;
    std::cout << i;

    // Затваряме файла, когато сме приключи с ползването му
    txtInFile.close();

    // Отваряме двоичен файл за писане
    std::ofstream binOutFile;
    binOutFile.open("example.bin", std::ios::binary);

    // Писането в двоичен файл става с функцията write, на която подаваме указател в паметта
    // и на която казваме колко байта искаме да прочетем от паметта и да запишем във файла.
    char outBuf[20] = "abcde";
    binOutFile.write(outBuf, 5);

    // Затваряме файла, когато сме приключи с ползването му
    binOutFile.close();

    // Отваряме двоичен файл за четене
    std::ifstream binInFile;
    binInFile.open("example.bin", std::ios::binary);

    // Четенето от двоичен файл става с функцията read, на която подаваме указател в паметта
    // и на която казваме колко байта искаме да прочетем от файл и да запишем на този адрес в паметта.
    char inBuf[20];
    binInFile.read(inBuf, 5);
    inBuf[5] = 0;

    std::cout << inBuf << std::endl;

    // Затваряме файла, когато сме приключи с ползването му
    binInFile.close();

    return 0;
}