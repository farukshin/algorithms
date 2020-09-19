# Длинная арифметика

```
void da_read(const string& s, vector<int>& a)
{
    for (int i = (int)s.length(); i > 0; i -= 9)
        if (i < 9)
            a.push_back(atoi(s.substr(0, i).c_str()));
        else
            a.push_back(atoi(s.substr(i - 9, 9).c_str()));
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void da_plus(vector<int>& a, vector<int>& b)
{
    int carry = 0;
    const int base = 1000 * 1000 * 1000;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back(0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
}

void da_minus(vector<int>& a, vector<int>& b)
{
    int carry = 0;
    const int base = 1000 * 1000 * 1000;
    for (size_t i = 0; i < b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry)  a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void da_print(vector<int>& a)
{
    printf("%d", a.empty() ? 0 : a.back());
    for (int i = (int)a.size() - 2; i >= 0; --i)
        printf("%09d", a[i]);
    //cout << endl;
}
```
