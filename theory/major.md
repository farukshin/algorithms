## Мажорирующий элемент

### Поиска элемента, встречающегося N/2 раз за O(n)

```
ll findMajorityElement(vector<ll>&a)
{
    ll count = 0;
    ll candidate;
    for (int i = 0; i < N; i++)
        if (count == 0)
            candidate = a[i], count++;
        else
            count+= (a[i] == candidate ? 1 : -1);            
   return candidate;
}
```

### Поиска элемента, встречающегося N/k раз

```
vector<ll> findMajorityElement(vector<ll>&a, int K)
{
    map<ll, int> candidates;   
    for(int i = 0; i < N; i++)
        if (candidates.count(a[i]))
            candidates[a[i]]++;
        else
            if (candidates.size() < K - 1)
            candidates[a[i]] = 1;
            else 
                for (auto element: candidates)
                {
                    candidates[element]--;
                    if candidates[element] == 0
                        candidates.erase(element);
                }
   
    for (auto candidate: candidates)
        candidates[candidate] = 0;
   
    for (int i = 0; i < N; i++)
        if (candidates.count(a[i]))
        candidates[a[i]]++;
   
    vector<ll> ans;
    for (auto candidate : candidates)
        if candidates[candidate] > N / K
            ans.push_back(candidate)
     
    return ans;
}
```