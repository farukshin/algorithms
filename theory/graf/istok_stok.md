# Поиск истоков и стоков

```
void istok_stok(vector<vector<int>>& ms, const int countNode, vector<int>& istok, vector<int>& stok)
{
    istok.clear();
    stok.clear();

    for (int i = 0; i < countNode; i++)
    {
        bool success = true;
        for (int j = 0; j < countNode && success; j++)
            if (ms[i][j] != 0)
                success = false;
        if (success)
            stok.push_back(i);
    }

    for (int i = 0; i < countNode; i++)
    {
        bool success = true;
        for (int j = 0; j < countNode && success; j++)
            if (ms[j][i] != 0)
                success = false;
        if (success)
            istok.push_back(i);
    }
}
```
