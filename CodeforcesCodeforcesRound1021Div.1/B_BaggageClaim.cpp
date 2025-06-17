//  The wedding was charming, if a little gauche
//  There's only so far as new money goes
//  They picked out a home and called it "Holiday House"

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/

// const int MOD = 998244353;
const int MOD = 1000000007;

template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular()
        : value()
    {
    }
    template <typename U>
    Modular(const U& x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x)
    {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type& operator()() const
    {
        return value;
    }
    template <typename U>
    explicit operator U() const
    {
        return static_cast<U>(value);
    }
    constexpr static Type mod()
    {
        return T::value;
    }

    Modular& operator+=(const Modular& other)
    {
        value += other.value;
        value -= (value >= mod()) * mod();
        return *this;
    }
    Modular& operator-=(const Modular& other)
    {
        value -= other.value;
        value += (value < 0) * mod();
        return *this;
    }
    template <typename U>
    Modular& operator+=(const U& other)
    {
        return *this += Modular(other);
    }
    template <typename U>
    Modular& operator-=(const U& other)
    {
        return *this -= Modular(other);
    }
    Modular& operator++()
    {
        return *this += 1;
    }
    Modular& operator--()
    {
        return *this -= 1;
    }
    Modular operator++(int)
    {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int)
    {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const
    {
        return Modular(-value);
    }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type&
    operator*=(const Modular& rhs)
    {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type&
    operator*=(const Modular& rhs)
    {
        int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type&
    operator*=(const Modular& rhs)
    {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other)
    {
        return *this *= Modular(inverse(other.value, mod()));
    }

    friend const Type& abs(const Modular& x)
    {
        return x.value;
    }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename V, typename U>
    friend V& operator>>(V& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs)
{
    return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs)
{
    return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs)
{
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs)
{
    return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b)
{
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number)
{
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number)
{
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number)
{
    return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number)
{
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = MOD;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//     if (k < 0 || k > n) {
//         return 0;
//     }
//     while ((int) fact.size() < n + 1) {
//         fact.push_back(fact.back() * (int) fact.size());
//         inv_fact.push_back(1 / fact.back());
//     }
//     return fact[n] * inv_fact[k] * inv_fact[n - k];
// }

//	https://github.com/the-tourist/algo/

template <typename T>
class graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    vector<edge> edges;
    vector<vector<int>> g;
    int n;
    vector<bool> vis;

    graph(int _n)
        : n(_n)
    {
        g.resize(n);
        vis.assign(n, 0);
    }

    virtual int add(int from, int to, T cost) = 0;
};

int node;
int edge;
int tt;
//	https://github.com/the-tourist/algo/

template <typename T>
class undigraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::vis;

    undigraph(int _n)
        : graph<T>(_n)
    {
    }

    int add(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({ from, to, cost });
        return id;
    }

    void dfs(int u)
    {
        vis[u] = 1;
        node++;
        for (auto e : g[u]) {
            edge++;
            int t = edges[e].to;
            if (t == u) {
                t = edges[e].from;
            }
            if (t == u) {
                tt++;
            }
            if (!vis[t]) {
                dfs(t);
            }
        }
    }

    Mint ans()
    {
        Mint t = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                edge = 0;
                node = 0;
                tt = 0;
                dfs(i);
                dbg(i);
                dbg(edge);
                dbg(node);
                edge /= 2;
                tt /= 2;
                if (edge + 1 == node) {
                    t *= node;
                } else if (edge == node) {
                    t *= (2 - tt);
                } else {
                    t = 0;
                }
            }
        }
        return t;
    }
};

void evermore()
{
    int n, m, k;
    cin >> n >> m >> k;
    undigraph<int> G(n * m);

    int pu = 0, pv = 1;
    bool c = 1;

    for (int i = 0; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (i && c) {
            if (abs(pu - u) + abs(pv - v) != 2) {
                c = 0;
                continue;
            }
            if (u == pu) {
                G.add(u * m + (v + pv) / 2, u * m + (v + pv) / 2);
            } else if (v == pv) {
                G.add((u + pu) / 2 * m + v, (u + pu) / 2 * m + v);
            } else {
                G.add(u * m + pv, pu * m + v);
            }
        }
        pu = u;
        pv = v;
    }
    dbg("e");
    if (c == 0) {
        cout << 0 << nl;
        return;
    }

    cout << G.ans();
    cout << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while (number_of_albums--) {
        evermore();
    }
    return 0;
}
// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/2097/B
