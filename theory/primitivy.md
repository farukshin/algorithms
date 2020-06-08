## Наибольший общий делитель (НОД)

```
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
```

## Наименьшее общее кратное (НОК)

```
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
```
