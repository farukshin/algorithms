# read_ss_from_ms

```
void read_ss_from_ms(vector<vector<int>>& ss, const int& n) {

    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        {
            int cur;
            cin >> cur;
            if (cur)
                ss[i].push_back(j);
        }

}
```
