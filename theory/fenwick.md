## Дерево Фенвика

Дерево Фенвика — это структура данных, дерево на массиве, которая обладает следующими свойствами:
* позволяет вычислять значение некоторой обратимой операции F на любом отрезке [L; R] за логарифмическое время;
* позволяет изменять значение любого элемента за O(log N);
* требует памяти O(N);

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


## Дерево Фенвика (Atcoder)

```

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

```

Пример использования

```
void solve()
{
	ll n,q;
	cin>>n>>q;
	fenwick_tree<ll> fw(n);
	for(int i=0;i<n;i++)
	{
		ll cur;
		cin>>cur;
		fw.add(i, cur);
	}
	for(int i=0;i<q;i++)
	{
		int t,a,b;
		cin>>t>>a>>b;
		if(t==0) fw.add(a, b);
		else if(t==1) cout<<fw.sum(a,b)<<"\n";
	}
}

```