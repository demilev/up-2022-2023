# Седмица 13

## Динамична памет

### Лимитации при работа със стека

* Масиви с произволен размер
```c++
int n;
std::cin >> n;

int arr[] = ??? // как да създадем масив, чиито размер е точно n
```

* Връщане на указател към данни, които продължавата да живеят и след изпълнението на дадена функция

```c++
int* evens(int arr[], int size)
{
    int newArr[100]; // колко голям да е?

    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
            newArr[index++] = arr[i];
    }

    return newArr; // но паметта заделена за newArr ще бъде освободена след изпълнението на функцията
}
```

### Стек

```c++
int function(int x)
{
    int c = x + 3;

    return c;
}

int main()
{
    int a = 2;
    int b = 3;
    int c = function(a);

    std::cout << a + c;

    return 0;
}
```

### Heap

```c++
int main()
{
    int * elem;
    elem = new int;

    *elem = 5;
    std::cout << elem;

    delete elem;


    int * arr;
    arr = new int[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }


    delete[] arr;

    return 0;
}
```

## [Задачи](tasks.md) - [Решения](solutions/)
