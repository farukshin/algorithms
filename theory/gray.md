## Нахождение кода Грея


```
int g (int n) {
	return n ^ (n >> 1);
}
```

## Нахождение обратного кода Грея

```
int rev_g (int g) {
	int n = 0;
	for (; g; g>>=1)
		n ^= g;
	return n;
}
```
