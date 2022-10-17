#include <iostream>

int main() {


    // Лошо наименоване на променливи
    int a1 = 1;
    int a2 = 2;
    int a3 = 10;

    // Добро наименоване на променливи
    int age = 10;
    double height = 170;
    double weight = 70;


    
    int a = 100;
    int b = 3000;
    double c = 33.4;
    double d = 42.42;
    
    // Оператор & ни дава адреса на променлива. Експериментирайте и вижте
    // какви адреси се ползват за вашите променливи. Забележете колко
    // байта се заделят за всяка променлива.
    // (това, което ще видите, много зависи от компилатора и машината, на която се изпълнява кодът)
    std::cout << "The address of a is " << &a << std::endl;
    std::cout << "The address of b is " << &b << std::endl;
    std::cout << "The address of c is " << &c << std::endl;
    std::cout << "The address of d is " << &d << std::endl;



    // c++ е строто типизиран език, но въпреки това има операции, които не са safe.
    // Поведението на програмата при тези два реда е недефинирано.
    double f;
    double f1 = f + 1;


    // Safe conversions - такива при които от "по-малък" тип конвертираме в "по-голям" тип.
    // При тях информация не се губи.
    char x = 'a';
    int numX = x;
    char xCopy = numX;

    std::cout << "Original char " << x << " . New char " << xCopy << std::endl;
    
    // Unsafe conversions - такива при които от "по-голям" тип конвертираме в "по-малъ" тип.
    // При тях информация се губи.
    int largeNumber = 1234567;
    char sym = largeNumber;
    int largeNumberCopy = sym;

    std::cout << "Original number " << largeNumber << " . New number " << largeNumberCopy << std::endl;


    
    return 0;
}