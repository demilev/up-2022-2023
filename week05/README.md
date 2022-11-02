# Седмица 5

## Масиви и низове

### Представяне в паметта

#### Променливи

```c+++
int a = 5;
int b = 10;
int c = 13;
```

| address | value | variable |
| ------- | ----- | -------- |
| 736424  | 5     |    a     |
| 736428  | -     |          |
| 736432  | -     |          |
| 736436  | 10    |    b     |
| 736440  | 13    |    c     |


#### Масиви

```c+++
int arr[5];
```

| address | value | variable |
| ------- | ----- | -------- |
| 736424  | -     |          |
| 736428  | 1     |  arr[0]  |
| 736432  | 2     |  arr[1]  |
| 736436  | 10    |  arr[2]  |
| 736440  | 13    |  arr[3]  |
| 736444  | 12    |  arr[4]  |
| 736444  | -     |          |



### Инициализация

```c++
int arr[5] = {16, 2, 77, 40, 12071};
int arr[] = {16, 2, 77, 40, 12071};
int arr[5] = {16, 2, 77};
```

### Достъп до елемент

```c++
int arr[5] = {16, 2, 77, 40, 12071};

int b = arr[1] + arr[2];
arr[2] = arr[3] + 1;
std::cout << arr[0];
```

```c++
int arr[3];

arr[0] = 1;
arr[1] = 7;
arr[2] = -5;
```

```c++
int arr[3];

for (int i = 0; i < 3; i++)
    std::cin >> arr[i];
```

### Операции с масиви

* място за съхранение на данни
* обхождане
* промяна на елементите
* търсене на елемент
* акумулация 


### Символни низове

```c++
char arr[] = "hello";
char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
char notTheSameArr[] = {'h', 'e', 'l', 'l', 'o'};

char arr[100];
std::cin >> arr;
std::cin.getline(arr, 100);
```


### Масиви като аргументи на функции

```c++
void myFunc1(int arr[], int size);

void myFunc2(char arr[]);


int main()
{
    int intArr[] = {1, 2, 3};
    char charArr[] = "hello world";

    myFunc1(intArr, 3);
    myFunc2(charArr);
}
```

## [Задачи](tasks.md)

## [Домашна работа](homework/)
