# Бинарное возведение в степень

```
long long binpow(long long a, long long n, long long m)
{
    a%=m, n%=m;
    if (n == 0)
        return 1 % m;

    if (n % 2 == 1)
        return (binpow(a, n - 1, m) * a) % m;
    else
        return binpow((a * a) % m, n / 2, m);
}
```
