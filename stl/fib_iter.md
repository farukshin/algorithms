# Числа Фибоначчи с итераторами

```
#include <iostream>

using namespace std;

class fibit{
    size_t i{0}, a{0}, b{1};
public:
    fibit() = default;
    explicit fibit(size_t _i): i{_i} {}
    
    size_t operator*() const {return b;}
    
    fibit& operator++(){
        ++i;
        const size_t old = b;
        b+=a;
        a=old;
        return *this;
    }
    
    bool operator!=(const fibit& o){
        return i != o.i;
    }
};

class fibit_range{
    size_t end_n;
public:
    fibit_range(size_t _end_n): end_n{_end_n} {}
    
    fibit begin() const {return fibit{};}
    fibit end() const {return fibit{end_n};}
    
};

int main() {
	
	for(const auto num : fibit_range(10))
	    cout<<num<<" ";
	
	return 0;
}
```