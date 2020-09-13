# Топологическая сортировка графа

```
void dfs(const int node, vector<vector<int>>& ss, vector<int>& used, vector<int>& ans, bool& success)
{
    used[node] = 1;
    for (auto chield : ss[node])
    {
        if (used[chield] == 1)
            success = false;

        if (used[chield] == 0)
            dfs(chield, ss, used, ans, success);
    }
    used[node] = 2;
    ans.push_back(node);
}

void topologicSort(vector<vector<int>>& ss, vector<int>& ans, bool& success)
{
    auto n = ss.size();
    ans.clear();
    fill(ans.begin(), ans.end(), -1);
    success = true;

    vector<int> used(n, 0);

    for (int i = 0; i < n && success; i++)
        if (!used[i])
            dfs(i, ss, used, ans, success);

    reverse(ans.begin(), ans.end());
}
```
