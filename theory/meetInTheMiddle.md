## Meet-in-the-middle

Дается массив чисел из N элементов. Сколькими способами можно выбрать подмножество чисел с суммой K?

Идея, раздельить массив на 2 части, решить задачу для каждой части и объединить результат.

```
// https://cses.fi/problemset/task/1628
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,k;
vector<ll> v;

map<ll,ll> createMap(int a, int b)
{
	int pos = b-a;
	map<ll, ll> res;
	for(int i=0;i<(1<<pos);i++)
	{
		ll curAns = 0;
		for(int j=0;j<pos && curAns<=k; j++)
			if(i & (1<<j)) curAns+= v[j+a];
		if(curAns>0 && curAns <= k) res[curAns]++;
	}
	return res;
}

void solve()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int cur;
		cin>>cur;
		if(cur<=k) v.push_back(cur);
	}
	sort(begin(v),end(v));
	int sx = v.size();
	auto mp1 = createMap(0, sx/2);
	auto mp2 = createMap(sx/2, sx);
	ll ans = (mp1.count(k) ? mp1[k] : 0) + (mp2.count(k) ? mp2[k] : 0);

	for(auto d:mp1)
		if(d.first >= k) break;
		else if(mp2.count(k-d.first)) ans+= (d.second * mp2[k-d.first]);
	cout<<ans;
}

int main()
{
	solve();
	return 0;
}
```
