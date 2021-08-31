## Нахождение наидлиннейшей возрастающей подпоследовательности


### Нахождение динамическим программированием O(n^2)

d[i] — это длина наидлиннейшей возрастающей подпоследовательности, оканчивающейся именно в элементе с индексом i

```
vector<int> dp(n+1,1); 
for (int i=0; i<n; i++)
	for (int j=0; j<i; ++j)
		if (v[j] < v[i])
			dp[i] = max (dp[i], 1 + dp[j]);
 
cout << max_element(begin(dp), end(dp));
```

С восстановлением пути

```
vector<int> dp(n,1); 
vector<int> par(n,-1);

for (int i=0; i<n; i++)
	for (int j=0; j<i; j++)
		if (v[j] < v[i] && 1 + dp[j] > dp[i])
			dp[i] = 1 + dp[j], par[i]=j;
 
int ans = dp[0],  pos = 0;
for (int i=0; i<n; i++)
	if (dp[i] > ans)
    {
		ans = dp[i];
		pos = i;
	}
cout << ans << "\n";
 
vector<int> path;
while (pos != -1) {
	path.push_back (pos);
	pos = p[pos];
}
reverse (path.begin(), path.end());
for (int i=0; i<(int)path.size(); i++)
	cout << path[i] << ' ';
```

### Динамика с двоичным поиском за O(n * log n)

d[i] — это число, на которое оканчивается возрастающая подпоследовательность длины i (а если таких чисел несколько — то наименьшее из них)

```
int dp[MAXN];
dp[0] = -INF;
for (int i=1; i<=n; ++i)
	dp[i] = INF;
 
for (int i=0; i<n; i++) {
	int j = int (upper_bound (begin(dp), end(dp), a[i]) - dp.begin());
	if (dp[j-1] < a[i] && a[i] < dp[j])
		dp[j] = a[i];
}
```

### Структуры данных за O(n * log n)

// todo