## Вычисление факториала по модулю

```
ll factmod (ll n, ll MOD) {
	ll res = 1;
	while (n > 1) {
		res = (res * ((n/MOD) % 2 ? MOD-1 : 1)) % MOD;
		for (ll i=2; i<=n%MOD; ++i)
			res = (res * i) % MOD;
		n /= MOD;
	}
	return res % p;
}
```