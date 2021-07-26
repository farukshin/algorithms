# Создание итерабельного диапазона данных

```
#include <iostream>
using namespace std;

class num_iter{
    int i;
public:
    explicit num_iter(int a=0): i{a} {};
    
    int operator*() const {return i;}
    
    num_iter& operator++() {++i; return *this;}
    
    bool operator!=(const num_iter& other) const {return i != other.i;}
    
};

class num_range{
    int a,b;
public:
    explicit num_range(int _a, int _b): a{_a}, b{_b} {};
    
    num_iter begin() const {return num_iter{a}; };
    
    num_iter end() const {return num_iter{b}; };
};

int main() {
	
	using item_type = pair<int, string>;
	
	for(const auto &l : num_range(100, 104))
	    cout<<l<<" ";
	
	return 0;
}

```