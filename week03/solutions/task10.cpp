#include <iostream>
#include <windows.h>

int main()
{   
    // Нова ключова дума - const. 
    // Тя ни позволява да дефинираме променливи константи - такива чиято стойност не може да бъде променена.
    const double C = 130.81; // до
    const double D = 146.83; // ре
    const double E = 164.81; // ми
    const double F = 174.61; // фа
    const double G = 196.00; // сол
    const double A = 220.00; // ла
    const double B = 246.94; // си

    int input = -1;
    while (input != 0)
    {

        std::cout << ">>: ";
        std::cin >> input;
        switch (input)
        {
        case 1:
            Beep(C, 500);
            break;
        case 2:
            Beep(D, 500);
            break;
        case 3:
            Beep(E, 500);
            break;
        case 4:
            Beep(F, 500);
            break;
        case 5:
            Beep(G, 500);
            break;
        case 6:
            Beep(A, 500);
            break;
        case 7:
            Beep(B, 500);
            break;
        }
    }

    return 0;
}