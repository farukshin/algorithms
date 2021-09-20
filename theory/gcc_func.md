## Полезные функции GCC

```
//Возвращает количество единиц в x .
int __builtin_parity (unsigned int x)
int __builtin_parityl (беззнаковое длинное)
int __builtin_popcountll (unsigned long long)


//Возвращает единицу плюс индекс наименее значащего 1-битного числа x или, если x равен нулю, возвращает ноль.
int __builtin_ffs (int x)
int __builtin_ffsl (long)
int __builtin_ffsll (long long)


//Возвращает четность x , то есть количество 1-битов в x по модулю 2.
int __builtin_parity (unsigned int x)
int __builtin_parityl (беззнаковое длинное)
int __builtin_parityll (unsigned long long)


//Возвращает количество ведущих 0-битов в x , начиная с позиции самого старшего бита. Если x равен 0, результат не определен.
int __builtin_clz (unsigned int x)
int __builtin_clzl (беззнаковое длинное)
int __builtin_clzll (unsigned long long)


//Возвращает количество завершающих 0-битов в x , начиная с позиции младшего разряда . Если x равен 0, результат не определен.
int __builtin_ctz (unsigned int x)
int __builtin_ctzl (беззнаковое длинное)
int __builtin_ctzll (unsigned long long)
```