## Система непересекающихся множеств

```
vector<int> leader;
vector<int> rang;

void make_set (int v) {
	leader[v] = v;
	rang[v] = 0;
}

void init (int n) {
	leader.resize(n);
	rang.resize(n);
	for(int i=0;i<n;i++)
		make_set(i);
}

int find_set (int v) {
	if (v == leader[v])
		return v;
	return leader[v] = find_set (leader[v]);
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rang[a] < rang[b])
			swap (a, b);
		leader[b] = a;
		if (rang[a] == rang[b])
			++rang[a];
	}
}
```
