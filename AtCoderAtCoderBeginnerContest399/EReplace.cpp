//  We always walked a very thin line
//  You didn't even hear me out
//  You never gave a warning sign
//  All this time

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif


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
vector<vector<int>> find_cycles(const graph<T> &g, int bound_cnt = 1 << 30, int bound_size = 1 << 30) {
    vector<int> was(g.n, -1);
    vector<int> st;
    vector<vector<int>> cycles;
    int total_size = 0;
    function<void(int, int)> dfs = [&](int v, int pe) {
        if ((int) cycles.size() >= bound_cnt || total_size >= bound_size) {
            return;
        }
        was[v] = (int) st.size();
        for (int id : g.g[v]) {
            if (id == pe) {
                continue;
            }
            auto &e = g.edges[id];
            int to = e.from ^ e.to ^ v;
            if (was[to] >= 0) {
                vector<int> cycle(1, id);
                for (int j = was[to]; j < (int) st.size(); j++) {
                    cycle.push_back(st[j]);
                }
                cycles.push_back(cycle);
                total_size += (int) cycle.size();
                if ((int) cycles.size() >= bound_cnt || total_size >= bound_size) {
                    was[v] = -2;
                    return;
                }
                continue;
            }
            if (was[to] == -1) {
                st.push_back(id);
                dfs(to, id);
                st.pop_back();
            }
        }
        was[v] = -2;
    };
    for (int i = 0; i < g.n; i++) {
        if (was[i] == -1) {
            dfs(i, -1);
        }
    }
    return cycles;
    // cycles are given by edge ids, all cycles are simple
    // breaks after getting bound_cnt cycles or total_size >= bound_size
    // digraph: finds at least one cycle in every connected component (if not broken)
    // undigraph: finds cycle basis
}

template <typename T>
vector<int> edges_to_vertices(const graph<T> &g, const vector<int> &edge_cycle) {
    int sz = (int) edge_cycle.size();
    vector<int> vertex_cycle;
    if (sz <= 2) {
        vertex_cycle.push_back(g.edges[edge_cycle[0]].from);
        if (sz == 2) {
            vertex_cycle.push_back(g.edges[edge_cycle[0]].to);
        }
    } else {
        for (int i = 0; i < sz; i++) {
            int j = (i + 1) % sz;
            auto &e = g.edges[edge_cycle[i]];
            auto &other = g.edges[edge_cycle[j]];
            if (other.from == e.from || other.to == e.from) {
                vertex_cycle.push_back(e.to);
            } else {
                vertex_cycle.push_back(e.from);
            }
        }
    } 
    return vertex_cycle;
    // only for simple cycles!
}

int n;
string s,t;

void solve(){
    cin >> n;
    
    cin >> s >> t;
    dbg(s);
    dbg(t);
    
    map<int,int> mp;
    vector<int> tttt;
    map<int,set<int>> mp2;

    for(int i = 0; i < n; i++){
        int a = char(s[i])-'a';
        int b = char(t[i])-'a';
        if (mp.count(a)){
            if (mp[a]!=b){
                cout << "-1"; return;
            }
        }else{
            tttt.push_back(b);
            mp[a] = b;
            mp2[b].insert(a);
        }
    }

    sort(tttt.begin(),tttt.end());
    
    bool cc = 1;

    if (tttt.size()==26){
        for(int i = 0; i < 26; i++){
            cc&=(tttt[i]==i);
        }
    }else{
        cc = 0;
    }

    ll ans = 0;
    dbg(mp);
    dbg(mp2);
    
    digraph<int> G(26);
    
    for(auto i:mp){
        if(i.first == i.second) continue;
        G.add(i.first,i.second);
    }

    vector<vector<int>> v = find_cycles(G);
    
    bool c = 1;
    
    for(auto i:v){
        vector<int> vertices = edges_to_vertices(G,i);
        set<int> ver;
        for(auto j:vertices){
            ver.insert(j);
        }
        dbg(ver);
        bool found = 0;
        for(auto j:ver){
            for(auto k:mp2[j]){
                if (ver.count(k)){
                    continue;
                }
                found = 1;
                c = 0;
                break;
            }
            if(found){
                break;
            }
        }
        if(!found){
            ans++;
        }
    }

    for(auto i:mp){
        if (i.first != i.second){
            ans++;
        }
    }

    if (c && (mp.size() == 26) && (mp2.size() == 26) && v.size() > 0){
        cout << "-1"; return;
    }

    cout << ans << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ttt = 1;
    while(ttt--){
        solve();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc399/tasks/abc399_e
