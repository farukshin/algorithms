# Поиск компонент связности

```
void bfs_compSv(vector<vector<int>>& ss, const int countNode, vector<int>& compSv, int& countCompSv)
{
    vector<bool> used(countNode, false);
    compSv.resize(countNode);
    fill(compSv.begin(), compSv.end(), 0);
    countCompSv = 0;

    for (int i = 0; i < countNode; i++)
        if (!used[i]) {
            countCompSv++;
            queue<int> q;
            q.push(i);
            used[i] = true;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                compSv[cur] = countCompSv;

                for (auto chield : ss[cur])
                    if (!used[chield])
                    {
                        used[chield] = true;
                        q.push(chield);
                    }
            }
        }
}
```
