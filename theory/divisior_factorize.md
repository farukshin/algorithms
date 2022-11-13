## Делители числа + факторизация

```
vector<int> divisior(int x)
{
    vector<int> ans;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i * i != x)
                ans.push_back(x / i);
        }
    sort(all(ans));
    return ans;
}
```


## Факторизация 


```
std::mt19937_64 mt{std::random_device{}()};
long long rnd(long long n) { return std::uniform_int_distribution<long long>(0, n - 1)(mt); }

bool is_prime(long long x)
{
    using u128 = __uint128_t;

    if (x == 2 || x == 3 || x == 5 || x == 7)
        return true;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
        return false;
    if (x < 121)
    {
        return x > 1;
    }

    long long d = (x - 1) >> __builtin_ctzll(x - 1);
    long long one = 1, minus_one = x - 1;

    auto pow = [](long long x, long long n, long long mod)
    {
        u128 res;
        x %= mod;
        if (n == 0)
        {
            res = 1;
            return res;
        }
        res = 1;
        u128 now = x;
        for (; n; n >>= 1, now = (now * now) % mod)
        {
            if (n & 1)
            {
                res = res * now % mod;
            }
        }
        return res;
    };

    auto ok = [&](long long a)
    {
        auto y = pow(a, d, x);
        long long t = d;

        while (y != one && y != minus_one && t != x - 1)
        {
            y = y * y % x;
            t <<= 1;
        }

        if (y != minus_one && t % 2 == 0)
            return false;
        return true;
    };

    if (x < (1ull << 32))
    {
        for (long long a : {2, 7, 61})
        {
            if (!ok(a))
                return false;
        }
    }
    else
    {
        for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
        {
            if (x <= a)
                return true;
            if (!ok(a))
                return false;
        }
    }

    return true;
}

long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, (a % b));
}

long long rho(long long n, long long c)
{
    using u128 = __uint128_t;

    assert(n > 1);
    long long cc = c;

    auto f = [&](long long x)
    {
        long long res;
        res = (((u128)x) * x + cc) % n;
        return res;
    };

    long long x = 1, y = 2, z = 1, q = 1;
    long long g = 1;

    long long m = 1LL << ((64 - __builtin_ctzll(n)) / 5);

    for (long long r = 1; g == 1; r <<= 1)
    {
        x = y;
        for (int i = 0; i < r; i++)
        {
            y = f(y);
        }
        for (long long k = 0; k < r && g == 1; k += m)
        {
            z = y;
            for (long long i = 0; i < std::min(m, r - k); i++)
            {
                y = f(y);
                long long w = (x - y) % n;
                if (w < 0)
                    w += n;
                q = ((u128)q * w) % n;
            }
            g = GCD(q, n);
        }
    }

    if (g == n)
    {
        do
        {
            z = f(z);
            long long w = (x - z) % n;
            if (w < 0)
                w += n;
            g = GCD(w, n);
        } while (g == 1);
    }

    return g;
}

long long prime_factor(long long n)
{
    assert(n > 1);
    if (is_prime(n))
        return n;

    for (int i = 0; i < 100; i++)
    {
        long long m = rho(n, rnd(n));
        if (is_prime(m))
            return m;
        n = m;
    }
    std::cerr << "failed\n";
    assert(false);
    return -1;
}

std::vector<std::pair<long long, int>> factor(long long n)
{
    static std::vector<std::pair<long long, int>> res;
    res.clear();

    for (long long i = 2; i <= 100 && i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            do
            {
                cnt++;
                n /= i;
            } while (n % i == 0);
            res.emplace_back(i, cnt);
        }
    }

    while (n > 1)
    {
        long long p = prime_factor(n);
        int cnt = 0;
        do
        {
            cnt++;
            n /= p;
        } while (n % p == 0);
        res.emplace_back(p, cnt);
    }

    std::sort(res.begin(), res.end());
    return res;
}

std::vector<long long> divisor(std::vector<std::pair<long long, int>> &fac)
{
    int sz = fac.size();
    if (sz == 0)
        return {1};

    std::vector<std::vector<long long>> x(sz);
    for (int i = 0; i < sz; i++)
    {
        auto [a, b] = fac[i];
        long long now = 1;
        for (int j = 0; j <= b; j++)
        {
            x[i].emplace_back(now);
            now *= a;
        }
    }

    std::vector<std::vector<long long>> res(sz);
    res[0] = x[0];

    for (int i = 1; i < sz; i++)
    {
        for (int j = 0; j < res[i - 1].size(); j++)
        {
            for (int k = 0; k < x[i].size(); k++)
            {
                res[i].emplace_back(res[i - 1][j] * x[i][k]);
            }
        }
    }

    std::sort(res[sz - 1].begin(), res[sz - 1].end());
    return res[sz - 1];
}
```

Использование 

```
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    auto ffa = factor(a);
    auto ffb = factor(b);
    auto fa = divisor(ffa);
    auto fb = divisor(ffb);
```
