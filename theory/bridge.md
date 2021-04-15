## Поиск мостов (offline)

Нужна доп.проверка на кратность ребер 

```
const int MAXN = 20005;
vector<int> ss[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
map<pair<int,int>, int> br;
map<pair<int,int>, int> sr;

void IS_BRIDGE(int a,int b)
{
	if(a>b) swap(a,b);
	br[{a,b}]++;
}

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<ss[v].size(); ++i) {
		int to = ss[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				IS_BRIDGE(v,to);
		}
	}
}
 
void find_bridges(int n) {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
}
```