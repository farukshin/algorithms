## vector


```
vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
const auto new_end (remove(begin(v), end(v), 2));
v.erase(neww_end, end(v));

const auto odd ([](int i) {return i%2 != 0; });
v.erase(remove(begin(v), end(v), odd), end(v));

v.srink_to_fit();
```

### Сохранение сортировки экземпляров класса std::vector

```

void insert_sorted(vector<string> &v, const string &word)
{
    const auto insert_pos (lower_bound(begin(v), end(v), word));
    v.insert(insert_pos, word);
}

...
vector<string> v {"some", "random", "words", "without", "order", "aaa", "yyy"};


assert(false == is_sorted(begin(v), end(v)));
sort(begin(v), end(v));
assert(true == is_sorted(begin(v), end(v)));

insert_sorted(v, "foobar");
insert_sorted(v, "zzz");
```
