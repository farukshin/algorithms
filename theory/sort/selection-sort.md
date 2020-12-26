## Сортировка выбором

```
void selection_sort(vector<ll> v, const ll size)
{
	for (int idx_i = 0; idx_i < size - 1; idx_i++) 
    {
        int min_idx = idx_i;

        for (int idx_j = idx_i + 1; idx_j < size; idx_j++) 
            if (v[idx_j] < v[min_idx]) 
                min_idx = idx_j;
        
        if (min_idx != idx_i) 
            swap(v[idx_i], v[min_idx]);
    }
}
```