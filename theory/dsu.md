## Система непересекающихся множеств

```
vector<int> parent;
vector<int> rang;

void make_set (int v) {
	parent[v] = v;
	rang[v] = 0;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rang[a] < rang[b])
			swap (a, b);
		parent[b] = a;
		if (rang[a] == rang[b])
			++rang[a];
	}
}
```