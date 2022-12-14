#include <iostream>

/*
    Напишете функция `void permutations(char str[])`, която отпечатва на екрана всички пермутации на символния низ `str`.
*/

// Помощна функция, която разменя символите на позиция i и j в низа str
void swap(char str[], int i, int j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

// Това ще е рекурсивната функция в програмата ни. Тя ще отпечатва
// всички пермутации на низа str, при които първите i на брой символа са фиксирани.
void permutationsHelper(char str[], int i, int n)
{
    // Ако всички символи са фиксирани, няма какви пермутации да градим, затова
    // просто отпечатваме текущото състояние на низа.
    if (i == n - 1)
    {
        std::cout << str << std::endl;
        return;
    }

    // Първите i символа са фиксирани. За да построим останалите пермутации,
    // на индекс i ще сложим всеки от оставащите символи и ще изградим всички пермутации,
    // при които първите i + 1 на брой символа са фиксирани.
    for (int j = i; j < n; j++)
    {
        // Слагаме текущия символ на i-та позиция.
        swap(str, i, j);

        // Отпечатваме всички пермутации, при които първите i + 1 елемента са фиксирани.
        permutationsHelper(str, i + 1, n);

        // Backtracking! - връщаме символа на оригиналната му позиция.
        swap(str, i, j);
    }
}

void permutations(char str[])
{
    // При първото извикване никой символ все още не е фиксиран.
    permutationsHelper(str, 0, strlen(str));
}

int main()
{
    char str[] = "ABC";

    permutations(str);

    return 0;
}