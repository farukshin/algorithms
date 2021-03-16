## Sqrt-декомпозиция

```
typedef long long ll;

int n, sqrt_len;
vector<ll> v, f;

void sqrt_init()
{
	sqrt_len = (int) sqrt (n) + 1;
	f.resize(sqrt_len);
	for (int i=0; i<n; ++i)
		f[i / sqrt_len] += v[i];
}

void sqrt_upd(int ind, ll k)
{
	ll diff = k - v[ind];
	v[ind] = k;
	f[ind/sqrt_len] += diff;
}

void sqrt_get(int l, int r)
{
	ll sum = 0;
	int c_l = l / sqrt_len,   c_r = r / sqrt_len;
	if (c_l == c_r)
		for (int i=l; i<=r; ++i)
			sum += v[i];
	else
	{
		for (int i=l, end=(c_l+1)*sqrt_len-1; i<=end; ++i)
			sum += v[i];
		for (int i=c_l+1; i<=c_r-1; ++i)
			sum += f[i];
		for (int i=c_r*sqrt_len; i<=r; ++i)
			sum += v[i];
	}
	cout<< sum<<"\n";
}

```
