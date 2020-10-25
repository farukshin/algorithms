## Решето Эратосфена

```
void eratosfen(int &n, vector<bool> &prime)
{
	prime.resize(n+1);
	fill(prime.begin(), prime.end(), true);

	prime[0] = prime[1] = false;
	for (int i=2; i<=n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j=i*i; j<=n; j+=i)
					prime[j] = false;
}
```
