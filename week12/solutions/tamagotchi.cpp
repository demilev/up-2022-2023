#include <iostream>

// Зад. 9
// Структура, описваща превозно средство
struct Vehicle
{
    // Всяко превозно средство си има име
    char name[20];
    // И скорост
    int speed;

    // Метод(член функция) за отпечатване данните на едно превозно средство
    void printStatus()
    {
        std::cout << "The name of the vehicle is: " << name << std::endl;
        std::cout << "The speed of the vehicle is: " << speed << std::endl;
    }
};

// Главната структура в нашата програма
struct Tamagotchi
{
    // Всяко тамагочи има име, енергия, точки атака и превозно средство
    char name[20];
    int energy;
    int attackPower;
    Vehicle vehicle;

    // Зад. 2
    // Метод за отпечатване данните на едно тамагочи
    void printStatus()
    {
        std::cout << "The name of the Tamagotchi is: " << name << std::endl;
        std::cout << "The energy of the Tamagotchi is: " << energy << std::endl;
        std::cout << "The attack power of the Tamagotchi is: " << attackPower << std::endl;
        std::cout << "The Tamagotchi has the following vehicle: " << std::endl;
        // Вместо да достъпваме данните на превозното средство, просто използваме неговия метод за печатане
        vehicle.printStatus();
    }

    // Зад. 5
    // Метод, който отпечатва на екрана speech, ако тамагочито има достатъчно енергия
    void speak(char *speech)
    {
        if (energy >= 2)
        {
            std::cout << "Tamagotchi " << name << " says " << speech << std::endl;
            energy -= 2;
        }
    }

    // Зад. 5
    // Метод, който добавя точки енергия към тамагочито
    void sleep(int hours)
    {
        energy += hours * 8;
        if (energy > 100)
            energy = 100;
    }

    // Зад. 6
    // Метод, който приема друго тамагочи и който намира кое от двете тамагочита е по-силно
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

    // Зад. 8
    // Метод, който сравнява текущото тамагочи с друго такова на база на точките им атака
    int compare(Tamagotchi other)
    {
        return attackPower - other.attackPower;
    }

    // Зад. 10
    // Метод, който сравнява текущото тамагочи с друго такова на база на скоростта на превозните им средства
    int compareSpeed(Tamagotchi other)
    {
        return vehicle.speed - other.vehicle.speed;
    }
};

// Зад. 3
// Функция за въвеждане на данните на тамагочи от клавиатурата
void readTamagotchi(Tamagotchi &t)
{
    std::cout << "Please input the name of the Tamagotchi: ";
    std::cin.getline(t.name, 20);
    std::cout << "Please input the energy of the Tamagotchi: ";
    std::cin >> t.energy;
    std::cout << "Please inout the attack power of the Tamagotchi: ";
    std::cin >> t.attackPower;

    // Игнорираме един символ, защото след въвеждането на attackPower и натискането на нов ред
    // във входния поток ще има един нов ред и името на превозното средство на тамагочито ще остане празно
    // без да сме имали шанс да го въведем
    std::cin.ignore();

    std::cout << "Please input the name of the vehicle of the Tamagotchi: ";
    std::cin.getline(t.vehicle.name, 20);
    std::cout << "Please input the speed of the vehicle of the Tamagotchi: ";
    std::cin >> t.vehicle.speed;

    // Същото правим и накрая
    std::cin.ignore();
}

// Зад. 7
// Функция, която приема масив от тамагочита и масив от песни и извиква метода speak за всяко тамагочи
void singSong(char *songs[], Tamagotchi tamagotchies[], int size)
{
    for (int i = 0; i < size; i++)
    {
        tamagotchies[i].speak(songs[i]);
    }
}

// Зад. 8
// Функция, която приема масив от тамагочита и връща най-силното такова на база на compare метода им
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

// Зад. 10
// Функция, която сортира масив от тамагочита на база на скоростта на превозните им средства
// Метод за сортиране - https://en.wikipedia.org/wiki/Selection_sort
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
    // Създаваме няколко тамагочита
    Tamagotchi t1;
    readTamagotchi(t1);

    Tamagotchi t2;
    readTamagotchi(t2);

    Tamagotchi t3;
    readTamagotchi(t3);

    Tamagotchi t4;
    readTamagotchi(t4);

    // Създаваме масив от тамагочита
    Tamagotchi tamagotchies[] = {t1, t2, t3, t4};

    char song[] = "hello";
    char song1[] = "world";
    char song2[] = "how are";
    char song3[] = "you";
    char *songs[] = {song, song1, song2, song3};

    // Караме ги да кажат нещо
    singSong(songs, tamagotchies, 4);

    // Намираме най-силното сред тях и му отпечтваме данните
    Tamagotchi strongest = findTheStrongest(tamagotchies, 4);
    strongest.printStatus();

    // Сортираме ги по скорост и отпечатваме най-бързото
    race(tamagotchies, 4);
    tamagotchies[0].printStatus();

    return 0;
}