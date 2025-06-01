//  Bold was waitress on our three year trip
//  Getting lunch down by the lakes
//  She said I looked like an American singer

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp"
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

    T ans()
    {
        int start = 0;
        int dest = n - 1;
        T msk = 0;
        T ans = 0;

        for (int b = 33; b >= 0; b--) {
            T t = msk | (T(1) << b);
            vector<bool> vis(n, 0);
            queue<T> q;
            vis[start] = 1;
            q.push(start);
            bool c = false;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == dest) {
                    c = true;
                    break;
                }
                for (auto i : g[u]) {
                    auto& e = edges[i];
                    int v = (e.from == u ? e.to : e.from);
                    if (!vis[v] && ((e.cost & t) == 0)) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            if (c) {
                msk = t;
            } else {
                ans |= (1 << b);
            }
        }

        return ans;
    }
};

void evermore()
{
    int n, m;
    cin >> n >> m;
    undigraph<ll> g(n);
    dbg("r");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add(u - 1, v - 1, w);
    }
    dbg("e");
    cout << g.ans();
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
// time-limit: 3000
