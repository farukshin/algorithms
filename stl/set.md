## Отсеиваем повторяющиеся слова в пользовательском вводе

```
set<string> st;

istream_iterator<string> iter {cin};
istream_iterator<string> end;

copy(iter, end, inserter(s, s.end()));

for(const auto world : st)
    cout<< word << " ";
```
