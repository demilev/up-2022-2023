#include <iostream>
#include <fstream>

struct Vehicle
{
    char name[20];
    int speed;
};

void save(char *fileName, Vehicle *vehicles, int size)
{
    std::ofstream file;
    file.open(fileName, std::ios::binary);

    file.write((char *) vehicles, size * sizeof(Vehicle));

    file.close();

    return;
}

void read(char *fileName, Vehicle *vehicles, int &size)
{
    std::ifstream file;
    file.open(fileName, std::ios::binary);

    int i = 0;
    while (file.read((char *) vehicles, sizeof(Vehicle)))
    {
        vehicles++;
        i++;
    }

    file.close();

    return;
}

Vehicle *readTxt(char *fileName, int &size)
{
    std::ifstream file;
    file.open(fileName);

    file >> size;
    Vehicle *vehicles = new Vehicle[size];

    for (int i = 0; i < size; i++)
    {
        file >> vehicles[i].speed;
        file.getline(vehicles[i].name, 20);
    }

    file.close();

    return vehicles;
}

int main()
{
    char txtFileName[] = "vehicles.txt";
    char binaryFileName[] = "vehicles.bin";
    int size = 0;

    Vehicle *vehicles = readTxt(txtFileName, size);
    save(binaryFileName, vehicles, size);
    delete[] vehicles;


    Vehicle vehiclesFromBinary[100];
    read(binaryFileName, vehiclesFromBinary, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << vehicles[i].speed << " " << vehicles[i].name << std::endl;
    }

    return 0;
}
