#include <iostream>

/*
    Да се напише програма, която кара потребителя да въведе коефициентите на полином и число х и след това да изкарва на екрана стойността на полинома в х.
*/

double polynomial(double array[], int size, double x)
{
    // Променлива, която ще пази x вдигнато на текущата степен. На всяка итерация ще умножаваме тази стойност по x, за да си спеситм всеки път да вдигаме x на степен.
    double xPowI = 1;
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        // array[i] е коефициентът пред x на степен i
        sum += array[i] * xPowI;
        xPowI *= x;
    }

    return sum;
}

int main()
{
    double arr[3] = {1, 2, 3}; // 1 + 2 * x + 3 * (x^2)

    std::cout << polynomial(arr, 3, 2) << std::endl;

    return 0;
}