## Новый возможности в С++17

### Cтруктурированные привязки (декомпозиция) для распаковки набора значений


```
std::pair<int, int> didivide(int dividend, int divisor)
{

}

auto [tchisl, znam] = didivide(16,3);
std::cout <<  tchisl << " " << znam;
```

```
struct vertex{
    unsigned id;
    std::string name;
    std::string lastname;
};

std::vector<vertex> v;
for(const auto &[id, name, lastname] : v)
    cout << id << " " << name << " " << lastname<<"\n";
```

### Ограничиваем область видимости переменных в if и switch

```
if (auto it (my_map.find(c)); it!=my_map.end())
{
    // it корректный, разыменовываем
}
else(
    // не разыменовываем
)

// здесь it недоступен, уменьшается кол-во переменных в области видимости
// увеличивается чистота кода и облегчается рефакторинг
```

```
if (std::lock_guard<std::mutex> lg {my_mutex}; some_condition) {
    // Делаем что-нибудь
}
```

### Инициализатор с фигурными скобками

```
int x1 = 1;
int x2 {1};
int x3 (1);

std::vector(int) v1   {1, 2, 3};
std::vector(int) v2 = {1, 2, 3};


std::vector(int) v3 (3, 20);
// v3 = {20, 20, 20}
```
