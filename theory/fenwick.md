## Дерево Фенвика

Дерево Фенвика — это структура данных, дерево на массиве, которая обладает следующими свойствами:
• позволяет вычислять значение некоторой обратимой операции F на любом отрезке [L; R] за логарифмическое время;
• позволяет изменять значение любого элемента за O(log N);
• требует памяти O(N);

Позволяет находить сумму на префиксе и изменять отдельные элементы за O(logN). Несмотря на одинаковую сложность, дерево Фенвика работает значительно быстрее дерева отрезков.

### Реализация дерева Фенвика для суммы для одномерного случая
```
vector<int> t;
int n;

void init (int nn)
{
	n = nn;
	t.assign (n, 0);
}

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}
```

### Реализация дерева Фенвика для минимума для одномерного случая

```
vector<int> t;
int n;

const int INF = 1000*1000*1000;

void init (int nn)
{
	n = nn;
	t.assign (n, INF);
}

int getmin (int r)
{
	int result = INF;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result = min (result, t[r]);
	return result;
}

void update (int i, int new_val)
{
	for (; i < n; i = (i | (i+1)))
		t[i] = min (t[i], new_val);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		update (i, a[i]);
}
```

### Реализация дерева Фенвика для суммы для двумерного случая

```
vector <vector <int> > t;
int n, m;

int sum (int x, int y)
{
	int result = 0;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1)
			result += t[i][j];
	return result;
}

void inc (int x, int y, int delta)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < m; j = (j | (j+1)))
			t[i][j] += delta;
}
```
