# Седмица 14

## [Файлове](https://cplusplus.com/doc/tutorial/files/)

### Текстови файлове

**Писане**

```c++
#include <iostream>
#include <fstream>

int main () {
    std::ofstream file;
    
    file.open("example.txt"); // отваряне
    
    file << "Hello World!"; // писане
    
    file.close(); // затваряне

    return 0;
}
```

**Четене**

```c++
#include <iostream>
#include <fstream>

int main () {
    std::ifstream file;
    
    file.open("example.txt"); // отваряне
    
    char text[20];
    file.getline(text, 20); // четене
    
    file.close(); // затваряне

    return 0;
}
```

### Двоични файлове

```c++
std::ifstream file;
file.open("example.bin", std::ios::binary);
char buf[20];
file.read(buf, 20);

std::ofstream file;
file.open("example.bin", std::ios::binary);
char buf[5] = "abcde";
file.write(buf, 5);
```



## [Задачи](tasks.md) - [Решения](solutions/)
