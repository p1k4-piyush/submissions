//  Take the road less traveled by
//  Tell yourself you can always stop
//  What started in beautiful rooms
//  Ends with meetings in parking lots

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n,m;

//	https://github.com/the-tourist/algo/
//	https://github.com/p1k4-piyush/templates/


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

        graph(int _n) : n(_n) {
            g.resize(n);
        }

        virtual int add(int from, int to, T cost) = 0;
};




template <typename T>
class digraph : public graph<T> {
    public:
        using graph<T>::edges;
        using graph<T>::g;
        using graph<T>::n;

        digraph(int _n) : graph<T>(_n) {

        }

        int add(int from, int to, T cost = 1) {
            assert(0 <= from && from < n && 0 <= to && to < n);
            int id = (int) edges.size();
            g[from].push_back(id);
            edges.push_back({from, to, cost});
            return id;
        }

        digraph<T> reverse() const {
            digraph<T> rev(n);
            for (auto &e : edges) {
                rev.add(e.to, e.from, e.cost);
            }
            return rev;
        }
};


template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
    assert(0 <= start && start < g.n);
    vector<T> dist(g.n, numeric_limits<T>::max());
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
            auto &e = g.edges[id];
            int to = e.from ^ e.to ^ i;
            if (dist[i] + e.cost < dist[to]) {
                dist[to] = dist[i] + e.cost;
                s.emplace(dist[to], to);
            }
        }
        dbg(s.top());
    }
    return dist;
    // returns numeric_limits<T>::max() if there's no path
}

vector<vector<bool>> arr;


void solve(){
    cin >> n >> m;
    digraph<ll> G(n*m);
    arr.assign(n,vector<bool>(m,0));
    char t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            arr[i][j] = (t=='.');
        }
    }
    vector<pair<int,int>> d1 = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<pair<int,int>> d2 = {{0,1},{1,0},{0,-1},{-1,0},{0,2},{2,0},{0,-2},{-2,0}};
    
    dbg(arr);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(auto t:d1){
                int i1 = i+t.first;
                int j1 = j+t.second;
                if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && arr[i1][j1]){
                    G.add(i*m+j,i1*m+j1,0);
                }
            }
            for(auto t:d2){
                int i1 = i+t.first;
                int j1 = j+t.second;
                if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m){
                    G.add(i*m+j,i1*m+j1,1);
                }
            }
        }
    }
    int s1,s2,e1,e2;
    cin >> s1 >> s2 >> e1 >> e2;
    s1--; s2--; e1--; e2--;
    vector<ll> ans = dijkstra(G,s1*m+s2);
    cout << ans[e1*m+e2] << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc400/tasks/abc400_d
