## Задача Иосифа

Рекурсивно за O(n)

```

int joseph (int n, int k) {
	return n>1 ? (joseph (n-1, k) + k - 1) % n + 1 : 1;
}

```

O(klogn) в 0-индексации
```

int joseph2 (int n, int k) {
	if (n == 1)  return 0;
	if (k == 1)  return n-1;
	if (k > n)  return (joseph (n-1, k) + k) % n;
	int cnt = n / k;
	int res = joseph (n - cnt, k);
	res -= n % k;
	if (res < 0)  res += n;
	else  res += res / (k - 1);
	return res;
}
```
