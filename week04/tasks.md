# Задачи за седмица 4

### Зад. 1 - [решение](solutions/task01.cpp)

Да се напишат няколко прости функции:
* `int absolute(int x)`, която връща абсолютната стойност на x ( т.е |x| ).
* `bool isEven(int x)`, която връща дали числото x е четно
* `char toLower(char sym)`, която връща малка буква по подадена главна такава
* `void printAll(int from, int until)`, която отпечатва на екрана всички числа от `from` до `to`

### Зад. 2 - [решение](solutions/task02.cpp)

Да се напише функция, която сравнява дали две числа дават един и същ остатък при деление на 3-то число. Трите числа да се подават като параметри на функцията.

### Зад. 3 - [решение](solutions/task03.cpp)

Да се напише функция `int arithSequenceSum(int start, int difference, int n)`, която връща сумата на първите n числа в аритметична прогресия с първи член start и разлика difference.


### Зад. 4 - [решение](solutions/task04.cpp)

Напишете функция `int primeNumbers(int n)`, която връща броя на простите числа от 1 до n.


### Зад. 5 - [решение](solutions/task05.cpp)

Напишете функция `bool isSubNumber(int find, int search)`, която проверява дали find се съдържа в search.

Примери:

```    
isSubNumber(12, 345) -> false
isSubNumber(12, 34125) -> true
```

### Зад. 6 - [решение](solutions/task06.cpp)

Напишете функция `void printAllSubNumbers(int number)`, която отпечатва всички числа, които се съдържат в number.

Пример:

```
printAllSubNumbers(128) -> 1,2,8,12,28,128
```


### Зад. 7 - [решение](solutions/task07.cpp)

Имплементирайте играта "Камък, Ножица, Хартия". За целта имплементирайте функции:
* `int rps(char firstPlayerMove, char secondPlayerMove)`, която приема ходовете на двама играчи и връща -1, ако е спечелил първият играч, 0, ако е равенство и 1, ако е спечелил вторият играч. Приемете, че символ 'r' кодира камък, символ 'p' кодира хартия, символ 's' кодира ножица. Пример:
```
rps('r', 's') -> -1
rps('r', 'p') -> 1
rps('r', 'r') -> 0
```
* `char randomMove()`, която генерира произволен ход('r', 'p' или 's')

Нека програмата приема за вход формата на играта, и на всеки рунд генерира произволен ход за компютъра и пита потребителя за неговия ход. Играта се играе, докато няма победител. На екрана се отпечатва крайният резултат. Пример:
```
> Please input the maximum number of rounds:
> 5 // Играта е 3 от 5. Който първи запише 3 победи, печели.
> Please input move 1:
> 'r'
> Computer: 's', Player: 'r' - Result 0-1
> Please input move 2:
> 'r'
> Computer: 's', Player: 'p' - Result 1-1
> Please input move 3:
> 'p'
> Computer: 'p', Player: 'p' - Result 1-1
> Please input move 4:
> 'p'
> Computer: 'r', Player: 'p' - Result 1-2
> Please input move 5:
> 'r'
> Computer: 's', Player: 'r' - Result 1-3
> The result is 1-3. You are the winner!
```

### Зад. 8 - [решение](solutions/task08.cpp)

Напишете функция `void printInBinary(int number)`, която отпечатва представянето на числото number в двоична бройна система.

### Зад. 9 - [решение](solutions/task09.cpp)

Напишете програма, която приема число n и след това кара потребителя да въведе n символа/букви. Програмата да изведе мажоритарния символ, в случай че има такъв. Мажоритарен симовл е този който се среща с честота повече от 50%.