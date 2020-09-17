# Матрица смежности -> список ребер

```
void ms_to_sr(vector<vector<int>>& ms, vector<pair<int, int>>& sr)
{
    int n = (int)ms.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j > i && ms[i][j] != 0)
                sr.push_back({ i, j });
}
```
