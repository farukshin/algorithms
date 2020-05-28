## Обход в ширину (bfs)

``` 
queue<int> q;
q.push(v);
used[v] = true;

while(!q.empty())
{
    v.q.front();
    q.pop();
    for(u : list[v])
    {
        if(used[u])
            continue;
        used[u] = true;
        q.push(u);
    }
}
```

