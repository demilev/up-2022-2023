# Седмица 11

## Рекурсия с връщане назад

```c++
backtrack(P, c) {
    if(reject(P, c)) {
        return;
    }
    if(accept(P, c)) {
        output(P, c);
    }
    s = first(P, c);
    while(s != NULL) {
        backtrack(P, s);
        s = next(P, c);
    }
}
```

## [Задачи](tasks.md)


https://meet.google.com/qnq-nhky-kzj