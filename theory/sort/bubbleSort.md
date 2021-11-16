## Сортировка пузырьком

```
struct BubbleSort {
    int n;
    vector<ll> v;
    BubbleSort(int _n)
    {
        n = _n;
        v.resize(n);
    }

    void load()
    {
        for (auto& d : v)
            cin >> d;
    }

    void sort()
    {
    	for(int i=0;i<n-1;i++)
	    	for(int j=n-1;j>i;j--)
	        	if(v[i]>v[j])
	        		swap(v[i], v[j]);
    }
};
```
