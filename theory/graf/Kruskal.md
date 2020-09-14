# Алгоритм Крускала (построение минимального остовного дерева)

```
void Kruskal(vector<pair<int, pair<int, int>>>& sr, const int& n, const int& m, vector<pair<int, int>>& res, vector<int>& tree_id)
{

    int cost = 0;
    tree_id.resize(n);

    sort(sr.begin(), sr.end());
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    for (int i = 0; i < m; i++)
    {
        int len = sr[i].first, a = sr[i].second.first, b = sr[i].second.second;
        if (tree_id[a] != tree_id[b])
        {
            cost++;
            res.push_back({ a, b });
            int old_id = tree_id[b], new_id = tree_id[a];
            for (int j = 0; j < n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }
}
```
