# Бинарное возведение в степень

```
long binpow(long a, long n, long m)
{
    if (n == 0)
        return 1 % m;

    if (n % 2 == 1)
        return (binpow(a, n - 1, m) * a) % m;
    else
        return binpow((a * a) % m, n / 2, m);
}
```
