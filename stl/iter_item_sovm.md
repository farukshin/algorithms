# Совместимость собственного итерабельного диапазона данных с STL

```
#include <iostream>
#include <algorithm>
using namespace std;

class num_iter{
    int i;
public:
    explicit num_iter(int a=0): i{a} {};
    
    int operator*() const {return i;}
    
    num_iter& operator++() {++i; return *this;}
    
    bool operator!=(const num_iter& other) const {return i != other.i;}
    
    bool operator==(const num_iter& other) const {return !(*this != other);}
    
};

class num_range{
    int a,b;
public:
    explicit num_range(int _a, int _b): a{_a}, b{_b} {};
    
    num_iter begin() const {return num_iter{a}; };
    num_iter end() const {return num_iter{b}; };
};

int main() {
	
	num_range r {100, 110};
	auto [min_it, max_it] (minmax_element(begin(r), end(r)));
	cout<<*min_it << " "<< *max_it;
	
	return 0;
}

```