#include <iostream>
#include <fstream>

/*
    Да се напише програма, която прочита текстов файл в следния формат:

    # Задачи за седмица 15

    ### Зад. 1

    ...
    ...
    ...

    ### Зад. 2

    ...
    ...
    ...

    и която връща броя на задачите в този файл. Примете, че всеки ред във файла е до 1024 символа.
*/

int main()
{
    // Отваряме файла
    std::ifstream file;
    file.open("tasks.txt");

    char line[1024];

    int numberOfTasks = 0;

    // Започваме да четем ред по ред
    while (file.getline(line, 1024))
    {
        if (strlen(line) > 3)
        {
            // Ако текущият ред започва с 3 #, значи това е една задача
            if (line[0] == '#' && line[1] == '#' && line[2] == '#')
                numberOfTasks++;
        }
    }

    // Затваряме файла, когато сме приключили с ползването му
    file.close();

    std::cout << "The number of tasks is: " << numberOfTasks << std::endl;

    return 0;
}