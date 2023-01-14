#include <iostream>
#include <fstream>

/*
    Напишете програма, която позволява управляването на списък със задачи.
    При стартиране програмата да изчита от файл всички текущи задачи. Програмата да позволява три опции:

    1) Добавяне на нова задача към края на списъка
    2) Премахване на задача от списъка, защото е завършена
    3) Край - при избиране на тази опция програмата приключва и във файла се записва новото състояние на списъка
*/

// Написаното тук е едно възможно решение. Оставям го без коментари, за да се провокирате да го разберете сами.
// Едно възможно подобрение на програмата е да позволим динамичен размер на описанието на една задата. Помислете как може да стане това.

const int MAX_TASK_SIZE = 1024;

struct Task
{
    char description[MAX_TASK_SIZE];
    bool completed;
};

struct TODOList
{
    Task *tasks;
    int numberOfTasks;
    int completedTasks;
};

void completeTask(TODOList &list, int taskIndex)
{
    if (taskIndex < 1 || taskIndex > (list.numberOfTasks - list.completedTasks))
        return;

    int index = 1;
    int i = 0;
    while (index != taskIndex)
    {
        if (!list.tasks[i].completed)
            index++;
        i++;
    }

    list.tasks[i].completed = true;
    list.completedTasks++;

    return;
}

void addTask(TODOList &list, Task &task)
{
    Task *result = new Task[list.numberOfTasks + 1];

    for (int i = 0; i < list.numberOfTasks; i++)
        result[i] = list.tasks[i];

    result[list.numberOfTasks] = task;

    delete[] list.tasks;

    list.tasks = result;
    list.numberOfTasks++;
}

TODOList read(char *fileName)
{
    std::ifstream file;
    file.open(fileName);

    int size = 0;
    file >> size;
    file.ignore();

    Task *tasks = new Task[size];

    for (int i = 0; i < size; i++)
    {
        tasks[i].completed = false;
        file.getline(tasks[i].description, MAX_TASK_SIZE);
    }

    file.close();

    TODOList result;
    result.completedTasks = 0;
    result.numberOfTasks = size;
    result.tasks = tasks;

    return result;
}

void save(char *fileName, TODOList &list)
{
    std::ofstream file;
    file.open(fileName);

    int realSize = list.numberOfTasks - list.completedTasks;

    file << realSize << std::endl;

    for (int i = 0; i < list.numberOfTasks; i++)
    {
        if (!list.tasks[i].completed)
        {
            file << list.tasks[i].description << std::endl;
        }
    }

    file.close();

    return;
}

void print(TODOList &list)
{
    if ((list.numberOfTasks - list.completedTasks) == 0)
    {
        std::cout << "Your TODO list is empty!" << std::endl;
        return;
    }

    std::cout << "Your TODO list is: " << std::endl
              << std::endl;
    int index = 1;
    for (int i = 0; i < list.numberOfTasks; i++)
    {
        if (!list.tasks[i].completed)
        {
            std::cout << index << ". " << list.tasks[i].description << std::endl;
            index++;
        }
    }

    return;
}

void cleanUp(TODOList &list)
{
    delete[] list.tasks;

    return;
}

int main()
{
    char fileName[] = "todo.txt";

    TODOList list = read(fileName);

    int option = 3;

    do
    {
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        print(list);

        std::cout << std::endl;
        std::cout << "Please select an action: " << std::endl
                  << std::endl;
        std::cout << "1) Add new task " << std::endl;
        std::cout << "2) Complete task " << std::endl;
        std::cout << "3) Exit " << std::endl;

        std::cout << std::endl;
        std::cin >> option;
        std::cout << std::endl;

        switch (option)
        {
        case 1:
            Task newTask;
            newTask.completed = false;
            std::cout << "Input a description for the new task: " << std::endl;
            std::cin.ignore();
            std::cin.getline(newTask.description, MAX_TASK_SIZE);
            addTask(list, newTask);
            break;
        case 2:
            int taskIndex;
            std::cout << "Input the index of the task you want to complete: " << std::endl;
            std::cin >> taskIndex;
            completeTask(list, taskIndex);
            break;
        }

    } while (option != 3);

    save(fileName, list);
    cleanUp(list);

    return 0;
}
