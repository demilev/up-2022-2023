# Седмица 4

## Функции

### Дефиниране на функции

`type name ( parameter1, parameter2, ...) { statements }`

```c++
int plus(int a, int b)
{
    int result = a + b;
    return result;
}
```

### Функции без резултат

```c++
void print(int a)
{
    std::cout << a;
}
```

### Scope

```c++
int plus(int a, int b)
{
    a += b;
    return a;
}

int main() {
    int a = 3;
    {
        int a = 5;
        std::cout << a << std::endl;
        a += 5;
    }

    std::cout << plus(a, 5) << std::endl;
    std::cout << a << std::endl;
    return 0;
}

```

## [Задачи](tasks.md)