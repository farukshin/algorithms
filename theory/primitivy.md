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

## Расширенный алгоритм Евклида

```
ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
```
