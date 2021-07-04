## Эффективно изменяем ключи элементов std::map

```
#include <iostream>
#include <map>

using namespace std;

template<typename M>
void print(const M &m){
    cout<< "Race placement:\n";
    for(const auto &[placement, driver] : m)
        cout<< placement <<" "<< driver<<"\n";
}

int main()
{
	map<int, string> mp {
	    {1, "Mario"},
	    {2, "Tood"},
	    {3, "Koopa"}
	};
	print(mp);

	{
	    auto a (mp.extract(1));
	    auto b (mp.extract(3));
	    swap(a.key(), b.key());

	    mp.insert(move(a));
	    mp.insert(move(b));
	}
	print(mp);

	return 0;
}
```
