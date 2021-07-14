## Алгоритм Прима (построение минимального остовного дерева)


### Случай плотных графов: алгоритм за O(n^2)
```
// входные данные
int n;
vector < vector<int> > g;
const int INF = 1000000000; // значение "бесконечность"
 
// алгоритм
vector<bool> used (n);
vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;
for (int i=0; i<n; ++i) {
	int v = -1;
	for (int j=0; j<n; ++j)
		if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
			v = j;
	if (min_e[v] == INF) {
		cout << "No MST!";
		exit(0);
	}
 
	used[v] = true;
	if (sel_e[v] != -1)
		cout << v << " " << sel_e[v] << endl;
 
	for (int to=0; to<n; ++to)
		if (g[v][to] < min_e[to]) {
			min_e[to] = g[v][to];
			sel_e[to] = v;
		}
}
```

### Случай разреженных графов: алгоритм за O(m log n)

```
// входные данные
int n;
vector < vector < pair<int,int> > > g;
const int INF = 1000000000; // значение "бесконечность"
 
// алгоритм
vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;
set < pair<int,int> > q;
q.insert (make_pair (0, 0));
for (int i=0; i<n; ++i) {
	if (q.empty()) {
		cout << "No MST!";
		exit(0);
	}
	int v = q.begin()->second;
	q.erase (q.begin());
 
	if (sel_e[v] != -1)
		cout << v << " " << sel_e[v] << endl;
 
	for (size_t j=0; j<g[v].size(); ++j) {
		int to = g[v][j].first,
			cost = g[v][j].second;
		if (cost < min_e[to]) {
			q.erase (make_pair (min_e[to], to));
			min_e[to] = cost;
			sel_e[to] = v;
			q.insert (make_pair (min_e[to], to));
		}
	}
}
```