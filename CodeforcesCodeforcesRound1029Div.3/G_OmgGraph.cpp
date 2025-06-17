//  I was so ahead of the curve, the curve became a sphere
//  Fell behind all my classmates, and I ended up here
//  Pouring out my heart to a stranger
//  But I didn't pour the whiskey

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

template <typename T>
class undigraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

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
};

//	https://github.com/the-tourist/algo/

template <typename T>
vector<T> dijkstra(const graph<T>& g, int start)
{
    assert(0 <= start && start < g.n);
    vector<T> dist(g.n);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> s;
    dist[start] = 0;
    s.emplace(dist[start], start);
    while (!s.empty()) {
        auto [expected, i] = s.top();
        s.pop();
        if (dist[i] != expected) {
            continue;
        }
        for (int id : g.g[i]) {
            auto& e = g.edges[id];
            int to = e.from ^ e.to ^ i;
            if (dist[i] + e.cost < dist[to]) {
                dist[to] = dist[i] + e.cost;
                s.emplace(dist[to], to);
            }
        }
    }
    return dist;
    // returns numeric_limits<T>::max() if there's no path
}

template <typename T>
struct My_int {
public:
    T mx = T();

    My_int()
        : mx(INT_MAX)
    {
    }

    My_int(T t)
        : mx(t)
    {
    }

    My_int operator+(const My_int& other) const
    {
        return My_int<T>(max(mx, other.mx));
    }

    bool operator<(const My_int& other) const
    {
        return mx < other.mx;
    }

    bool operator==(const My_int& other) const
    {
        return mx == other.mx;
    }

    T get()
    {
        return mx;
    }
};

void evermore()
{
    int n, m;
    cin >> n >> m;
    undigraph<My_int<int>> G(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G.add(u, v, w);
    }

    vector<My_int<int>> v = dijkstra(G, 0);
    vector<My_int<int>> v2 = dijkstra(G, n - 1);
    int ans = INT_MAX;
    for (auto e : G.edges) {
        ans = min(ans, e.cost.get() + (v[e.from] + e.cost + v2[e.to]).get());
    }
    cout << ans << nl;
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
// problem-url: https://codeforces.com/contest/2117/problem/G
