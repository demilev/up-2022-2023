#include <iostream>
#include <cmath>

/*
   Напишете функция `bool isSubNumber(int find, int search)`, която проверява дали find се съдържа в search.
*/

/*
    Можем да забележим следното:
    12 се съдържа в 3125, а 312 завършва на 12
    12 се съдържа в 412, а 412 завършва на 12
    12 се съдържа в 1255, а 12 завършва на 12

    т.е. едно число се съдържа във второ <=> има подчисло на второто, което завършва на първото.

    Това наблюдение веднага ни насочва как да разделим проблема на подпроблеми.
*/

// Познатата ни от предишни седмици логика за преброяване на цифрите на дадено число
int countDigits(int number)
{
    int count = 0;
    while (number > 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}

// Функция, която проверява дали дадено число завършва на друго
bool endsWith(int find, int search)
{
    int numberOfDigits = countDigits(find);
    int powerOfTen = std::pow(10, numberOfDigits);

    // Взимаме последните n цифри на числото по познат от предишните седмици начин.
    int remainder = search % powerOfTen;

    return remainder == find;
}

/* проверяваме дали find е subNumber на search */
bool isSubNumber(int find, int search)
{

    while (search >= find && search > 0)
    {
        if (endsWith(find, search))
        {
            return true;
        }
        search = search / 10; // махаме последната цифра на search
    }

    // Ако изпълнението на функцията стигне до тук, това значи,
    // че нито веднъж в цикъла не сме влязали в тялото на if условието.
    // Това означава, че нито едно подчисло на search не завършва на find.
    // A това означава, че find не се съдържа в search.
    return false;
}

int main()
{
    std::cout << isSubNumber(12, 3125) << std::endl;
}