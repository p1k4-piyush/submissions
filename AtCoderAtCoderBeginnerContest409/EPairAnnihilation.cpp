//  Our coming-of-age has come and gone
//  Suddenly the summer, it's clear
//  I never had the courage of my convictions
//  As long as danger is near

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;
#define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

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

    graph(int _n)
        : n(_n)
    {
        g.resize(n);
    }

    virtual int add(int from, int to, T cost) = 0;
};

//	https://github.com/the-tourist/algo/
vector<int> arr;
ll ans = 0;

template <typename T>
class forest : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

    forest(int _n)
        : graph<T>(_n)
    {
    }

    int add(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        assert(id < n - 1);
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({ from, to, cost });
        return id;
    }

    T dfs(int u, int p)
    {
        T s = arr[u];
        for (auto e : g[u]) {
            int v = edges[e].to;
            if (v == u) {
                v = edges[e].from;
            }
            if (v == p)
                continue;
            T sv = dfs(v, u);
            ans += abs(sv) * edges[e].cost;
            s += sv;
        }
        return s;
    }
};

void evermore()
{
    int n;
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    forest<ll> G(n);
    int u, v, w;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        G.add(u, v, w);
    }

    G.dfs(0, -1);
    cout << ans;

    cout << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    while (number_of_albums--) {
        evermore();
    }
    return 0;
}
// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc409/tasks/abc409_e
