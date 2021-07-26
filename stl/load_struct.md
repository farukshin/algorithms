# Заполнения обобщенных структур данных

```
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <deque>
using namespace std;

int main() {
	
	istream_iterator<int> int_cin {cin};
	istream_iterator<int> end_cin;
	
	deque<int> q;
	copy(int_cin, end_cin, back_inserter(q));
	
	istringstream s {"123 5456 789"};
	auto dequeMidle (next(begin(q), static_cast<int>(q.size())/2));
	
	copy(istream_iterator<int>{s}, {}, inserter(q, dequeMidle));
	
	initializer_list<int> il {-1, 2, 3};
	copy(begin(il), end(il), front_inserter(q));
	
	copy(begin(q), end(q), ostream_iterator<int>{cout, " "});
	cout<<"\n";
	
	return 0;
}

```