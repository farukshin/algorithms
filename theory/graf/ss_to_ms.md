# Список смежности -> матрица смежности

```
void ss_to_ms(vector<vector<int>>& ss, int& countNode, vector<vector<int>>& ms)
{
    ms.resize(countNode);
    for (int i = 0; i < countNode; i++)
        for (int j = 0; j < countNode; j++)
            ms[i].push_back(0);

    for (int i = 0; i < countNode; i++)
        for (int j = 0; j < ss[i].size(); j++)
            ms[i][ss[i][j]] = 1;
}
```
