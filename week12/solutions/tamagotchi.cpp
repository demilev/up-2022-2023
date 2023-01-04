#include <iostream>

struct Vehicle {
    char name[20];
    int speed;

    void printStatus()
    {
        std::cout << "The name of the vehicle is: " << name << std::endl;
        std::cout << "The speed of the vehicle is: " << speed << std::endl;
    }
};


struct Tamagotchi
{
    char name[20];
    int energy;
    int attackPower;
    Vehicle vehicle;

    void printStatus()
    {   
        std::cout << "The name of the Tamagotchi is: " << name << std::endl;
        std::cout << "The energy of the Tamagotchi is: " << energy << std::endl;
        std::cout << "The attack power of the Tamagotchi is: " << attackPower << std::endl;
        std::cout << "The Tamagotchi has the following vehicle: " << std::endl;
        vehicle.printStatus();
    }

    void speak(char *speech)
    {
        if (energy >= 2)
        {
            std::cout << "Tamagotchi " << name << " says " << speech << std::endl;
            energy -= 2;
        }
    }

    void sleep(int hours)
    {
        energy += hours * 8;
        if (energy > 100)
            energy = 100;
    }

    void fightWith(Tamagotchi other)
    {
        if (attackPower > other.attackPower)
        {
            std::cout << "The winner is " << name << std::endl;
        }
        if (attackPower == other.attackPower)
        {
            std::cout << "It's a draw" << std::endl;
        }
        if (attackPower < other.attackPower)
        {
            std::cout << "The winner is " << other.name << std::endl;
        }
    }

    int compare(Tamagotchi other)
    {
        return attackPower - other.attackPower;
    }

    int compareSpeed(Tamagotchi other)
    {
        return vehicle.speed - other.vehicle.speed;
    }
};

void readTamagotchi(Tamagotchi &t)
{
    std::cout << "Please input the name of the Tamagotchi: ";
    std::cin.getline(t.name, 20);
    std::cout << "Please input the energy of the Tamagotchi: ";
    std::cin >> t.energy;
    std::cout << "Please inout the attack power of the Tamagotchi: ";
    std::cin >> t.attackPower;

    std::cin.ignore();

    std::cout << "Please input the name of the vehicle of the Tamagotchi: ";
    std::cin.getline(t.vehicle.name, 20);
    std::cout << "Please input the speed of the vehicle of the Tamagotchi: ";
    std::cin >> t.vehicle.speed;

    std::cin.ignore();
}

void singSong(char *songs[], Tamagotchi tamagotchies[], int size)
{
    for (int i = 0; i < size; i++)
    {
        tamagotchies[i].speak(songs[i]);
    }
}

Tamagotchi findTheStrongest(Tamagotchi tamagotchies[], int size)
{
    int candidate = 0;

    for (int i = 0; i < size; i++)
    {
        if (tamagotchies[i].compare(tamagotchies[candidate]) > 0)
            candidate = i;
    }

    return tamagotchies[candidate];
}

// https://en.wikipedia.org/wiki/Selection_sort
void race(Tamagotchi tamagotchies[], int size)
{
    for (int i = 0; i < size; i++)
    {   
        int fastest = i;
        for (int j = i; j < size; j++)
        {
            if (tamagotchies[j].compareSpeed(tamagotchies[fastest]) > 0)
                fastest = j;
        }
        std::swap(tamagotchies[i], tamagotchies[fastest]);
    }
}

int main()
{
    Tamagotchi t1;
    readTamagotchi(t1);
    
    Tamagotchi t2;
    readTamagotchi(t2);

    Tamagotchi t3;
    readTamagotchi(t3);

    Tamagotchi t4;
    readTamagotchi(t4);

    Tamagotchi tamagotchies[] = {t1, t2, t3, t4};

    char song[] = "hello";
    char song1[] = "world";
    char song2[] = "how are";
    char song3[] = "you";
    char *songs[] = {song, song1, song2, song3};

    singSong(songs, tamagotchies, 4);

    Tamagotchi strongest = findTheStrongest(tamagotchies, 4);
    strongest.printStatus();

    race(tamagotchies, 4);
    tamagotchies[0].printStatus();

    return 0;
}