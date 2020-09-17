# Список ребер -> матрица смежности

```
void sr_to_ms(vector<pair<int, int>> &sr, int &countNode, vector<vector<int>> &ms, bool orient = false)
{
    ms.resize(countNode);
    for (int i = 0; i < countNode; i++)
        for (int j = 0; j < countNode; j++)
            ms[i].push_back(0);

    for (auto r : sr)
    {
        ms[r.first][r.second] = 1;
        if (!orient)
            ms[r.second][r.first] = 1;
    }
}

```
