#include <iostream>

/*
   Напишете програма, която приема число n и след това кара потребителя да въведе n символа/букви.
   Програмата да изведе мажоритарния символ, в случай че има такъв. Мажоритарен симовл е този който се среща с честота повече от 50%.
*/



// Подробно обяснение и визуализация на алгоритъма - https://www.cs.utexas.edu/users/moore/best-ideas/mjrty/index.html
int main()
{
    int n;
    std::cin >> n;
    
    char input;
    std::cin >> input;

    char current = input;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        std::cin >> input;
        
        if (count == 0)
        {
            current = input;
            count = 1;
        }
        else 
        {
            if(input == current)
                count++;
            else
                count--;
        }  
    }

    std::cout << "The majority element is " << current << std::endl;

    return 0;
}