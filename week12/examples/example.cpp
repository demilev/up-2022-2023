#include <iostream>

struct Student
{
    int fn;
    char name[50];

    void printName()
    {
        std::cout << "The name is: " << name << std::endl;
    }
};

void print(char str[])
{
    std::cout << "str is: " << str << std::endl;
}

void printName(Student& s)
{   
    s.fn = 123;
    std::cout << "The name is: " << s.name << std::endl;
}

int main()
{
    int x = 3;
    int y = 5;
    int z = x + y;
    bool b = true;

    Student s;
    s.fn = 81352;
    
    std::cin.getline(s.name, 50);
    
    // print(s.name);
    
    // printName(s);
    
    s.printName();
    // std::cout << "The fn is: " << s.fn << std::endl;

    Student s1;
    std::cin.getline(s1.name, 50);

    s1.printName();


    return 0;
}