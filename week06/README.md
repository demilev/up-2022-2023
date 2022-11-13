# Седмица 6

## Масиви и низове

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

### Вградени функции за работа със символни низове

```c++
char arr[] = "group3";
strlen(arr);

char source[10] = "group3";
char target[10];
strcpy(target, source);

char arr1[10] = "abcp";
char arr2[10] = "abdf";
strcmp(arr1, arr2);
```

## [Задачи](tasks.md) - [Решения](solutions.md)
