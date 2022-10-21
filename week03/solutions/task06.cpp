#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    Напишете програма, която генерира произволно число от 1 до n (n се въвежда от потребителя) и започва да пита потребителя да познае числото.
    Ако числото му е твърде малко, програмата му казва и го пита отново, ако е твърде голямо пак изписва подходящо съобщение и цикълът продължава. 
    Когато потребителят най-накрая познае числото, програмата извежда колко опита са били нужни, за да познае, и приключва.
*/
int main()
{   
    // Захранваме генератора, за да не ни дава едно и също число при всяко изпълнение на програмата.
    // Документация - https://en.cppreference.com/w/cpp/numeric/random/rand
    std::srand(std::time(nullptr));

    int n;
    std::cin >> n;
    
    int attempts = 0;    
    int randomNumber = std::rand() % n; // Не ни интересува как работи тази функция. Достатъчно ни е да знаем, че ще ни даде произволно число.
    int guess;


    // Хубав пример за използване на do while цикъл. Знаем, че ще ни трябва поне един опит,
    // за да познаем числото, така че със сигурност ще има поне една итерация на цикъла.
    // В такъв случай ползваме do while, защото по-добре пасва на намеренията ни.
    do {
        
        std::cin >> guess;

        if (guess < randomNumber)
        {
            std::cout << "Your guess is less than the acutal nubmer" << std::endl;
        }

        if (guess > randomNumber)
        {
            std::cout << "Your guess is more than the acutal nubmer" << std::endl;
        }
        
        attempts++;
    } while(guess != randomNumber); // Малко по-различен тип крайно условие. Този път не знаем предварително колко итерации ще има цикъла.

    std::cout << "It took you " << attempts << " attempts to guess the number" << std::endl;

    return 0;
}