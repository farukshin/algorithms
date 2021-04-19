## Динамика по битовым маскам

```
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
	cin>>v[i];
	
vector<int> sum((1<<n), 0);
for(int mask=0; mask< (1<<n); mask++)
	for(int i=0;i<n;i++)
		if(mask & (1<<i))
		{
			sum[mask] = sum[mask^(1<<i)] + v[i];
			break;
		}
```

### Наивный перебор (без динамики)

```
for (int i = 0; i < 1 << n; i++)
{
    ll curSum = 0;
    for (int j = 0; j < n; j++)
        if (i & 1 << j)
            curSum += arr[j];
} 

```