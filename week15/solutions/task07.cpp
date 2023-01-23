#include <iostream>

/*
    Нека е дадена структура `Student`, която представя един студент. Всеки студент има име и дата на раждане(ден, месец и година).
    Напишете функция, която приема масив от студенти и ден от годината и която връща студента, който най-скоро има рожден ден след този ден от годината.
*/

// Помощна структура, която представлява дата
struct Date
{
    // Всяка дата си има година, месец и ден от месеца
    int dayOfMonth;
    int month;
    int year;

    // Метод, който ни връща колко дни има от текущата дата до даден ден в годината
    int daysFromDayOfYear(int dayOfYear, int year)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        int monthStartDayOfYear;
        switch (month)
        {
        case 1:
            monthStartDayOfYear = 1;
            break;
        case 2:
            monthStartDayOfYear = 32;
            break;
        case 3:
            monthStartDayOfYear = 60;
            break;
        case 4:
            monthStartDayOfYear = 91;
            break;
        case 5:
            monthStartDayOfYear = 121;
            break;
        case 6:
            monthStartDayOfYear = 152;
            break;
        case 7:
            monthStartDayOfYear = 182;
            break;
        case 8:
            monthStartDayOfYear = 213;
            break;
        case 9:
            monthStartDayOfYear = 244;
            break;
        case 10:
            monthStartDayOfYear = 274;
            break;
        case 11:
            monthStartDayOfYear = 305;
            break;
        case 12:
            monthStartDayOfYear = 335;
            break;
        default:
            monthStartDayOfYear = -367;
        }

        if (month > 2 && isLeap)
        {
            monthStartDayOfYear++;
        }

        return (monthStartDayOfYear + dayOfMonth - 1) - dayOfYear;
    }
};

// Структурата, представляваща един студент
struct Student
{
    char name[20];
    Date birthday;
};

// Функция, която намира най-малък елемент в масив по някакво свойство
Student closestBirthday(Student students[], int size, int dayOfYear, int year)
{
    int closest = 0;
    int days = students[closest].birthday.daysFromDayOfYear(dayOfYear, year);
    if (days < 0)
        days = 367;

    for (int i = 0; i < size; i++)
    {
        int currentDays = students[i].birthday.daysFromDayOfYear(dayOfYear, year);
        if (currentDays >= 0 && currentDays < days)
        {
            days = currentDays;
            closest = i;
        }
    }

    return students[closest];
}

int main()
{
    Student s1, s2, s3, s4;

    char name1[] = "Mitko";
    char name2[] = "Adi";
    char name3[] = "Petko";
    char name4[] = "Viki";

    strcpy(s1.name, name1);
    s1.birthday.dayOfMonth = 10;
    s1.birthday.month = 1;
    s1.birthday.year = 2003;

    strcpy(s2.name, name2);
    s2.birthday.dayOfMonth = 30;
    s2.birthday.month = 4;
    s2.birthday.year = 2003;

    strcpy(s3.name, name3);
    s3.birthday.dayOfMonth = 8;
    s3.birthday.month = 5;
    s3.birthday.year = 2003;

    strcpy(s4.name, name4);
    s4.birthday.dayOfMonth = 19;
    s4.birthday.month = 5;
    s4.birthday.year = 2003;

    Student students[] = {s1, s2, s3, s4};

    std::cout << closestBirthday(students, 4, 121, 2023).name << std::endl;

    return 0;
}