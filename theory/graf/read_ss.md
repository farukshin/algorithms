# read_ss

```
void read_ss(vector<vector<int>>& ss, const int& m, const bool& orient = true) {

    for (int i = 0;i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ss[a].push_back(b);
        if (!orient)
            ss[b].push_back(a);
    }

}

```
