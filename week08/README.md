# Седмица 8

## Референции и указатели


### Референции


```c++
int a = 5;
int &b = a;

int c = b + 3;
b = 10;

std::cout << a; // 10
```

| address | value | variable |
| ------- | ----- | -------- |
| 736424  | -     |          |
| 736428  | 5     |  a, b    |
| 736432  | 8     |  c       |
| 736436  |       |          |
| 736440  |       |          |
| 736444  |       |          |


### Указатели

```c++
int a = 5;
int *b = &a;
```

| address | value  | variable |
| ------- | -----  | -------- |
| 736424  | -      |          |
| 736428  | 5      |  a       |
| 736432  |        |          |
| 736436  |        |          |
| 736440  | 736428 |   b      |
| 736444  |        |          |


```c++
int a = 5;
int *b = &a;

std::cout << *b; // 5 

*b = 3;

std::cout << a; // 3

int c = 10;
b = &c;

std::cout << *b; // 10
```

### Операции с указатели

* дерефенциране - `*p`
* пренасочване - `p = &x`
* местене - `p + 5` , `p - 2`, `p++`

### Указатели и масиви

```c++
int arr[] = {1, 2, 3};
int *p = arr;

for (int i = 0; i < 3; i++)
{
    std::cout << arr[i];
}

for (int i = 0; i < 3; i++)
{
    std::cout << *(p + i);
}
```

### Референции и указатели като параметри на функции

```c++

void incrementReference(int &a)
{
    a++;
}

void incrementPointer(int *a)
{
    (*a)++;
}

int main()
{
    int x = 3;
    incrementReference(x);
    incrementPointer(&x);

    std::cout << x; // 5
}
```


## [Задачи](tasks.md) - [Решения](solutions/)
