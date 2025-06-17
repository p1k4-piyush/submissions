//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green

#include "bits/stdc++.h"
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
#define int ll

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
    vector<T> dp;
    vector<T> has;
    int n;

    graph(int _n)
        : n(_n)
    {
        g.resize(n);
        // dp.assign(n,T(-1));
    }

    virtual int add(int from, int to, T cost) = 0;
};

const ll inf = ll(4e18) + 5;
const char nl = '\n';

//	https://github.com/the-tourist/algo/

template <typename T>
class digraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::dp;
    using graph<T>::has;

    digraph(int _n)
        : graph<T>(_n)
    {
    }

    int add(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        edges.push_back({ from, to, cost });
        return id;
    }

    digraph<T> reverse() const
    {
        digraph<T> rev(n);
        for (auto& e : edges) {
            rev.add(e.to, e.from, e.cost);
        }
        return rev;
    }

    void add2(T t)
    {
        for (int i = 60; i >= 0; i--) {
            if (!(t & (T(1) << i))) {
                continue;
            }
            if (!has[i]) {
                has[i] = t;
                return;
            }
            // t ^= has[i];
        }
    }

    T minr(T t)
    {
        for (int i = 60; i >= 0; i--) {
            if (has[i] && ((has[i] ^ t) < t)) {
                t ^= has[i];
            }
        }
        return t;
    }

    void dfs(int u)
    {
        for (auto e : g[u]) {
            int from = edges[e].from;
            int to = edges[e].to;
            T cost = edges[e].cost;
            if (dp[to] == T(-1)) {
                dp[to] = dp[from] ^ cost;
                dfs(to);
            } else {
                T tt = dp[from] ^ dp[to] ^ cost;
                add2(tt);
            }
        }
    }
    T ans()
    {
        T upr = 1 << 10;
        vector<vector<char>> vis(n, vector<char>(upr, 0));
        queue<pair<T, T>> q;
        vis[0][0] = 1;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [u, x] = q.front();
            q.pop();
            for (int eid : g[u]) {
                auto& e = edges[eid];
                int v = (e.from == u ? e.to : e.from);
                int nx = x ^ int(e.cost);
                if (!vis[v][nx]) {
                    vis[v][nx] = 1;
                    q.emplace(v, nx);
                }
            }
        }
        for (int x = 0; x < upr; ++x) {
            if (vis[n - 1][x])
                return x;
        }
        return T(-1);
    }
    T ans2()
    {
        dp.assign(n, T(-1));
        dp[0] = T(0);
        has.assign(64, 0);
        dfs(0);
        T ans = dp[n - 1];
        if (ans == T(-1)) {
            return ans;
        }
        return minr(ans);
    }
};

void evermore()
{
    int n, m;
    cin >> n >> m;
    digraph<int> g(n);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        g.add(u, v, w);
    }
    cout << g.ans() << nl;
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
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc410/tasks/abc410_d
