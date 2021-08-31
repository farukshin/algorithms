## K-ая порядковая статистика за O (N)

```
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
    cout<<"Start array:\n";
    for(auto d:v)
    	cout<<d<<" ";
    cout<<"\n";
 
    nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    cout << "The median is " << v[v.size()/2] << '\n';
    for(auto d:v)
    	cout<<d<<" ";
    cout<<"\n";
 
    nth_element(v.begin(), v.begin()+1, v.end(), greater<int>());
    cout << "The second largest element is " << v[1] << '\n';
    for(auto d:v)
    	cout<<d<<" ";
    cout<<"\n";
}
```

```
Start array:
5 6 4 3 2 6 7 9 3 
The median is 5
3 2 3 4 5 6 7 9 6 
The second largest element is 7
9 7 6 6 5 3 4 3 2 
```