# Битовые операции

|Оператор|Символ|Пример|Операция|
|-|-|-|-|
|Побитовый сдвиг влево	|<<	|x << y|	Все биты в x смещаются влево на y бит|
|Побитовый сдвиг вправо	|>>	|x >> y	|Все биты в x смещаются вправо на y бит|
|Побитовое НЕ	|~|	~x	|Все биты в x меняются на противоположные|
|Побитовое И	|&|	x & y	|Каждый бит в x И каждый соответствующий ему бит в y|
|Побитовое ИЛИ	|l|	x l y	|Каждый бит в x ИЛИ каждый соответствующий ему бит в y|
|Побитовое исключающее ИЛИ (XOR)|	^|	x ^ y	|Каждый бит в x XOR с каждым соответствующим ему битом в y|


```
#ifdef _MSC_VER
#include <intrin.h>
#endif

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
```