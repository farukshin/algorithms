## Сортировка слиянием, подсчет инверсий

```
struct Mergesort {
    int n;
    vector<ll> v;
    ll inversionCnt = 0;
    Mergesort(int _n)
    {
        n = _n;
        v.resize(n);
    }

    void load()
    {
        for (auto& d : v)
            cin >> d;
    }

    void merge(int l, int mid, int r)
    {
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (v[i] <= v[j]) {
                i++;
            }
            else {
                j++;
                inversionCnt += mid - i + 1;
            }
        }
        sort(v.begin() + l, v.begin() + r + 1);
    }

    void mergesort(int l, int r)
    {
        if (l < r) {
            int mid = (r + l) / 2;
            mergesort(l, mid);
            mergesort(mid + 1, r);
            merge(l, mid, r);
        }
    }
};

void solve()
{
    int n;
    while (cin >> n, n != 0) {
        Mergesort mergs(n);
        mergs.load();
        mergs.mergesort(0, n - 1);
        cout << mergs.inversionCnt << "\n";
    }
}
```
