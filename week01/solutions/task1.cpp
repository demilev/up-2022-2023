#include <iostream>

/*
    Да се напише програма, която по въведени тегло в килограми и височина в метри, изчислява BMI
*/
int main() {
    
    // декларираме две променливи, които ще ползваме, за да съхраняват височината и теглото
    double height, weight;

    // Подобряваме малко взаимодействието с програмата като първо информираме потребителя, 
    // че трябва да въведе килограмите си, а после да въведен височината си.
    // Реално можеше и просто да направим std::cin >> weight >> height;

    std::cout << "Please correctly input your weight in kg: ";
    std::cin >> weight;

    std::cout << "Please correctly input your height in m: ";
    std::cin >> height;

    // Отпечтваме резултата на екрана като използваме BMI формулата
    std::cout << "Your BMI is: " << weight / (height * height) << std::endl;


    return 0;
}