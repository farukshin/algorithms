## Нахождение максимального потока. Алгоритм Диница

```
const ll MAXARR = 500;
ll n, s, t, ms[MAXARR][MAXARR];

ll f[MAXARR][MAXARR], d[MAXARR], ptr[MAXARR], q[MAXARR];

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt) {
		ll v = q[qh++];
		for (ll to=0; to<n; ++to)
			if (d[to] == -1 && f[v][to] < ms[v][to]) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[t] != -1;
}

ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (ll & to=ptr[v]; to<n; ++to) {
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, ms[v][to] - f[v][to]));
		if (pushed) {
			f[v][to] += pushed;
			f[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}

ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (ll pushed = dfs (s, LLONG_MAX))
			flow += pushed;
	}
	return flow;
}
```
