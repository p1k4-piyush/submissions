//  And it took you five whole minutes
//  To pack us up and leave me with it
//  Holdin' all this love out here in the hall

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
        vector<bool> seen;
        vector<bool> used;
        vector<int> p;
        int c;

        graph(int _n) : n(_n) {
            g.resize(n);
            seen.assign(n,0);
            used.assign(n,0);
            p.assign(n,-1);
            c=0;
        }

        virtual int add(int from, int to, T cost) = 0;
};

vector<tuple<int,int,int>> ans;

//	https://github.com/the-tourist/algo/


template <typename T>
class forest : public graph<T> {
    public:
        using graph<T>::edges;
        using graph<T>::g;
        using graph<T>::n;
        using graph<T>::seen;
        using graph<T>::used;
        using graph<T>::c;
        using graph<T>::p;
        forest(int _n) : graph<T>(_n) {
  
        }

        int add(int from, int to, T cost = 1) {
            assert(0 <= from && from < n && 0 <= to && to < n);
            int id = (int) edges.size();
            assert(id < n - 1);
            g[from].push_back(id);
            g[to].push_back(id);
            edges.push_back({from, to, cost});
            return id;
        }
        
        pair<T,T> dfs(int u,int par){
            pair<T,T> ans1 = {1,u};
            p[u] = par;
            seen[u] = true;
            for(auto j:g[u]){
                int i = edges[j].from;
                if(i == u){
                    i = edges[j].to;   
                }
                if(i != par && !used[i]){
                    pair<T,T> prev = dfs(i,u);
                    prev.first++;
                    ans1 = max(ans1,prev);
                }
            }
            
            return ans1;
        }
        void solver(){
            for(int i = 0; i < n; i++){
                if(used[i]||seen[i]) continue;
                pair<T,T> p1 = dfs(i,-1);
                dbg("e");
                pair<T,T> p2 = dfs(p1.second,-1);
                ans.push_back({p2.first,max(p1.second,p2.second),min(p1.second,p2.second)});
                dbg(ans.back());
                T k = p2.second;
                while(k != -1){
                    used[k] = 1;
                    c++;
                    k = p[k];
                }
            }    
        }
        void solve(){
            while(c != n){
                seen.assign(n,0);
                solver();
                // c++;
            }
        }
};




int n;

void solve(){
    cin >> n;
    int u,v;
    forest<int> tree(n);
    ans.resize(0);
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--; v--;
        tree.add(u,v);
    }
    tree.solve();
    
    
    sort(ans.begin(),ans.end(),greater<tuple<int,int,int>>());
    dbg(ans);
    for(auto i:ans){
        cout << get<0>(i) << " " << get<1>(i)+1 << " " << get<2>(i)+1 << " ";
    }
    cout << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 5000
// problem-url: https://codeforces.com/contest/2107/problem/D
