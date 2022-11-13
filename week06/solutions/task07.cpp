#include <iostream>
#include <cmath>

/*
    Нека имаме списък от N точки в равнината: p[0], p[1].... p[N - 1]. 
    Да се напише функция която намира дължината на пътя от p[0] до p[N - 1], като можем да се придвижим от p[i] до p[i + 1] само по права линия.
*/

// Функция, която намира разстоянието между две точки в равнината. Вече сме я виждали в Зад. 5, Седмица 2
double distance(double x1, double y1, double x2, double y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double path(double xCoords[], double yCoords[], int size)
{
    // Ще минем през всички точки на масива без последната,
    // като за всяка ще добавим разстоянието до следващата.
    // За N точки имаме N-1 отсечки между тях.
    double result = 0;
    for (int i = 0; i < size - 1; i++)
    {
        result += distance(xCoords[i], yCoords[i], xCoords[i + 1], yCoords[i + 1]);
    }
    return result;
}

int main()
{   
    // Имаме точките (0, 0), (1, 0) и (1, 1)
    double xCoords[3] = {0, 1, 1};
    double yCoords[3] = {0, 0, 1};
    
    std::cout << path(xCoords, yCoords, 3) << std::endl;

    return 0;
}