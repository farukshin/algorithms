## семантика подсказок для вставки элементов std::map::insert

```
std::map<std::string, size_t> mp{
    {"b",1},
    {"c",2},
    {"d",3}
};

auto insert_it(stg::end(mp));

for(const auto &s : {"z", "y", "x", "w"}){
    insert_it = mp.insert(insert_it, {s, 1});
}

// в данном случае так делать не нужно
mp.inser(std::end(mp), {"a",1});
```
