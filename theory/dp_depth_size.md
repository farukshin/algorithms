# Нахождение глубин вершин (сверху вниз)

```
bool used[n];
vector<vector<int>> ss[n];
int tree_depth[n];

void dfs(int node)
{
    used[node] = true;
    for(auto chield:ss[node])
        if(!used[chield])
            tree_depth[chield] = tree_depth[node]+1, dfs(chield);
}

int main()
{
    tree_depth[0] = 0;
    dfs(0);
}
```
