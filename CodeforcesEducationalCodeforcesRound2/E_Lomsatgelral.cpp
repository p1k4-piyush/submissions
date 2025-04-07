//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all

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

vector<ll> ans1;
vector<ll> co;



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
class undigraph : public graph<T> {
    public:
        using graph<T>::edges;
        using graph<T>::g;
        using graph<T>::n;

        undigraph(int _n) : graph<T>(_n) {

        }

        int add(int from, int to, T cost = 1) {
            assert(0 <= from && from < n && 0 <= to && to < n);
            int id = (int) edges.size();
            g[from].push_back(id);
            g[to].push_back(id);
            edges.push_back({from, to, cost});
            return id;
        }
        map<ll,ll> dfs(int u,int p){
            vector<map<ll,ll>> v;
            int tt = 0;
            int idx = 0;
            for(auto i:g[u]){
                int t;
                if (edges[i].from != u){
                    t = edges[i].from;
                }else{
                    t = edges[i].to;
                }
                if (t == p){
                    continue;
                }
                v.push_back(dfs(t,u));
            }
            if(v.size() == 0){
                map<ll,ll> mp; mp[co[u]]=1;
                ans1[u] = co[u];
                return mp;
            }
            for(int i = 0; i < v.size(); i++){
                tt = max(tt,(int)v[i].size());
                if(tt == v[i].size()){
                    idx = i;
                }
            }
            v[idx][co[u]]++;
            for(int i = 0; i < v.size(); i++){
                if (i==idx) continue;
                for(auto j:v[i]){
                    v[idx][j.first]+=j.second;
                }
            }
            
            ll t = 0;
            ll mx = 0;
            for(auto i:v[idx]){
                if (i.second > mx){
                    mx = i.second;
                    t = i.first;
                }else if(i.second == mx){
                    t += i.first;
                }
            }
            ans1[u] = t;
            return v[idx];
        }
};






int n;

void solve(){
    cin >> n;
    co.assign(n,0);
    ans1.assign(n,0);
    undigraph<int> G(n);
    for(int i = 0; i < n; i++){
        cin >> co[i];
    }
    int u,v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--; v--;
        G.add(u,v);
    }
    G.dfs(0,0);
    
    for(auto i:ans1){
        cout << i << " ";
    }
    
    cout << nl;
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
// problem-url: https://codeforces.com/problemset/problem/600/E
