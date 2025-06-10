//  Time, curious time
//  Gave me no compasses, gave me no signs
//  Were there clues I didn't see?

#include "bits/stdc++.h"
#include <queue>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/blob/master/data/dsu.cpp

class dsu {
public:
    vector<int> p;
    int n;

    dsu(int _n)
        : n(_n)
    {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x)
    {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, d;
    bool operator<(Edge const& a) const
    {
        return d < a.d;
    }
    bool operator>(Edge const& a) const
    {
        return d > a.d;
    }
};

void evermore()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> arr(n, { 0, 0 });

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    dsu dsu(n + q);

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Edge t = { i, j, abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second) };
            pq.push(t);
        }
    }

    int N = n;

    for (int qq = 0; qq < q; qq++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            arr.push_back({ a, b });
            for (int i = 0; i < N; i++) {
                Edge t = { i, N, abs(arr[i].first - arr[N].first) + abs(arr[i].second - arr[N].second) };
                pq.push(t);
            }
            N++;
        } else if (t == 2) {
            int tt = dsu.get(0);
            bool c = 1;
            for (int i = 1; i < N; i++) {
                int t = dsu.get(i);
                if (tt != t) {
                    c = 0;
                    break;
                }
            }
            if (c) {
                cout << -1 << "\n";
                continue;
            }
            Edge e = pq.top();
            pq.pop();

            while (dsu.get(e.u) == dsu.get(e.v)) {
                e = pq.top();
                pq.pop();
            }

            int k = e.d;
            dsu.unite(e.u, e.v);

            while (!pq.empty() && pq.top().d == k) {
                auto& ee = pq.top();
                if (dsu.get(ee.u) != dsu.get(ee.v)) {
                    dsu.unite(ee.u, ee.v);
                }
                pq.pop();
            }
            cout << k << "\n";
        } else {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            cout << (dsu.get(u) == dsu.get(v) ? "Yes\n" : "No\n");
        }
    }

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
// problem-url: https://atcoder.jp/contests/abc409/tasks/abc409_f
