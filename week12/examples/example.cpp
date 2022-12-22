#include <iostream>

struct Student {
    int fn;
    char name[50];

    void print()
    {
        std::cout << "The name of the student is " << name << std::endl;
        std::cout << "The faculty number of the student is " << fn << std::endl;
    }
};

void printStudent(Student x)
{
    std::cout << "The name of the student is " << x.name << std::endl;
    std::cout << "The faculty number of the student is " << x.fn << std::endl;
}


int main()
{

    Student x;
    std::cin.getline(x.name, 50);
    std::cin >> x.fn;

    printStudent(x);

    x.print();
    return 0;
}