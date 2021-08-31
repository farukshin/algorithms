## Система непересекающихся множеств

```
struct Dsu {
	int n;
	vector<int> leader, rang, sz;

	Dsu(int _n): leader(_n), rang(_n), sz(_n) {
		iota(all(leader), 0);
	}

	int get(int v) {
		return v == leader[v] ? v : leader[v] = get(leader[v]);
	}

	int size(int v) {
		return sz(get(v));
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) {
			return false;
		}
		if (rang[u] < rang[v]) {
			swap(u, v);
		}
		leader[v] = u;
		sz[u]+=sz[v];
		if (rang[u] == rang[v]) {
			++rk[u];
		}
		return true;
	}
};

```
