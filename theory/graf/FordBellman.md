## Форд Беллман

### Без отрицательных циклов, без восстановления пути

```
struct edge {
	int a, b, cost;
};
 
int n, m, start=0;
vector<edge> e;
vector<int> dist(105, INT_MAX);
 
void FordBellmanNotNegativCycle() {
	dist[start] = 0;
	for (int i=0; i<n-1; ++i)
		for (int j=0; j<m; ++j)
			if (dist[e[j].a] < INT_MAX)
				dist[e[j].b] = min (dist[e[j].b], dist[e[j].a] + e[j].cost);
}
```