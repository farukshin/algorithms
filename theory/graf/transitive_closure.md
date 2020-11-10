## Транзитивное замыкание

```
void transitive_closure(vector<vector<int>> &ms, const int &n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ms[i][k] && ms[k][j]) {
					ms[i][j] = 1;
				}
			}
		}
	}
}
```