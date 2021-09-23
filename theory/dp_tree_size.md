# Нахождение размеров поддеревьев (снизу вверх)

```
bool used[n];
vector<vector<int>> ss[n];
int tree_size[n];

void dfs(int node)
{
    used[node] = true;
    tree_size[node] = 1;
    for(auto chield:ss[node])
        if(!used[chield])
            dfs(chield), tree_size[v] += tree_size[chield];
}

int main()
{
    dfs(0);
}
```
