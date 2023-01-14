#include <iostream>
#include <fstream>

/*
    Припомнете си структурата, описваща превозно средство, от седмица 12. Напишете функция, която:
        * записва списък от превозни средства в текстов файл
        * прочита списък от превозни средства от текстов файл
*/

// Познатата ни структура за превозно средство
struct Vehicle
{
    char name[20];
    int speed;
};

// Функция, която записва масив от превозни средства във файл
void save(char *fileName, Vehicle *vehicles, int size)
{
    std::ofstream file;
    file.open(fileName);

    // На първия ред записваме броя на превозните средства
    file << size << std::endl;

    for (int i = 0; i < size; i++)
    {
        // За всяко превозно средство на нов ред записваме първо скоростта му, а после името му
        file << vehicles[i].speed << " " << vehicles[i].name << std::endl;
    }

    // Накрая не забравяме да затворим файла
    file.close();

    return;
}

// Функция, която връща указател към масив от превозни средства, прочетени от файл
Vehicle *read(char *fileName, int &size)
{
    std::ifstream file;
    file.open(fileName);

    // Първо прочитаме бройката на превозните срества
    file >> size;
    // Заделяме динамично памет за точно толкова превозни средства, колкото ни трябват
    Vehicle *vehicles = new Vehicle[size];

    for (int i = 0; i < size; i++)
    {
        // За всяко превозно средство първо прочитаме скоростта му
        file >> vehicles[i].speed;
        // А след това и името
        file.getline(vehicles[i].name, 20);
    }

    // Накрая не забравяме да затворим файла
    file.close();

    return vehicles;
}

int main()
{
    char fileName[] = "vehicles.txt";
    int size = 0;

    // Прочитаме превозните средства
    Vehicle *vehicles = read(fileName, size);

    // Отпечатваме ги на екрана
    for (int i = 0; i < size; i++)
    {
        std::cout << vehicles[i].speed << " " << vehicles[i].name << std::endl;
    }

    // Записваме ги обратно файла. Съдържанието на файла след изпълнението на програмата трябва да е същото, както и преди.
    save(fileName, vehicles, size);

    // Накрая не забравяме да зачистим динамично заделената памет
    delete[] vehicles;

    return 0;
}
