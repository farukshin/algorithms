## Вставляем в map эффективно и по условию

Вставляем элементы в map без создания копии

```
#include <iostream>
#include <functional>
#include <list>
#include <map>

using namespace std;

struct billionaiere{
    string name;
    double dolllar;
    string country;
};

int main()
{
	list<billionaiere> billionaieres{
		{"Bill Gates", 86.0, "USA"},
		{"Warren Buffet", 75.6, "USA"},
		{"Jeff Bezos", 72.8, "USA"},
		{"Amancio Ortega", 71.3, "Spain"},
		{"Mark Zuckerberg", 56.0, "USA"},
		{"Carlos Slim", 54.5, "Mexico"}
	};

	map<string, pair<const billionaiere, size_t>> mp;

	for(const auto &b : billionaieres)
	{
		auto [iter, success] = mp.try_emplace(b.country, b, 1);
		if(!success)
			iter->second.second +=1;
	}

	for(const auto [key, value] : mp)
	{
		const auto &[b, count] = value;
		cout << b.country << " " << count << " " << b.name<<"\n";
	}

	return 0;
}
```
