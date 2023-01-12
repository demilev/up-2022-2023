#include <iostream>
#include <fstream>

int main () {
    std::ofstream file;
    
    file.open("example.txt"); // отваряне
    
    char text[20];
    std::cin.getline(text, 20);
    while (strlen(text) > 0)
    {
        file << text << std::endl;
        std::cin.getline(text, 20);
    }

    file.close(); // затваряне

    return 0;
}