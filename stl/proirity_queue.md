# Список дел с приоритетом

```
#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int main() {
	
	using item_type = pair<int, string>;
	
	initializer_list<item_type> il {
	    {1, "task1"},
	    {0, "task2"},
	    {5, "task3"},
	    {9, "task4"}
	};
	
	priority_queue<item_type> q;
	for(const auto &d :il)
	    q.push(d);
	while(!q.empty())
	{
	    auto cur = q.top();
	    q.pop();
	    cout<< cur.first<<" "<<cur.second<<"\n";
	}
	
	return 0;
}

```