# Матрица смежности -> список смежности

```
void ms_to_ss(vector<vector<int>> &ms, vector<vector<int>> &ss)
{
    int n = (int)ms.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (ms[i][j] != 0)
                ss[i].push_back(j);
}
```
