//  Sequin smile, black lipstick
//  Sensual politics
//  When you are young, they assume you know nothing

#include "bits/stdc++.h"
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

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
    vector<int> l, r, dp;
    int n;

    graph(int _n)
        : n(_n)
    {
        g.resize(n);
        l.resize(n);
        r.resize(n);
        dp.resize(n);
    }

    virtual int add(int from, int to, T cost) = 0;
};

//	https://github.com/the-tourist/algo/

template <typename T>
class undigraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::l;
    using graph<T>::r;
    using graph<T>::dp;
    ll ans = 0;

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

    void dfs(int u, int p)
    {
        int lo = l[u];
        for (auto e : g[u]) {
            int t = edges[e].to;
            if (t == u) {
                t = edges[e].from;
            }
            if (t == p) {
                continue;
            }
            dfs(t, u);
            lo = max(lo, dp[t]);
        }
        // dp[u] = lo;
        lo = min(lo, r[u]);
        dp[u] = lo;
        for (auto e : g[u]) {
            int t = edges[e].to;
            if (t == u) {
                t = edges[e].from;
            }
            if (t == p) {
                continue;
            }
            ans += max(T(0), dp[t] - lo);
        }
    }
};

void evermore()
{
    int n;
    cin >> n;
    undigraph<int> g(n);

    for (int i = 0; i < n; i++) {
        cin >> g.l[i] >> g.r[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        g.add(l, r);
    }
    g.dfs(0, 0);

    cout << g.ans + g.dp[0] << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PIKA
    auto album_start_time = std::chrono::high_resolution_clock::now();
#endif
    int number_of_albums = 1;
    cin >> number_of_albums;
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2062/D
