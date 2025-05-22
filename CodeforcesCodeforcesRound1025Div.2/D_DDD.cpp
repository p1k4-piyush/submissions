//  They don't me all of my cages were mental
//  So I got wasted like all my potential
//  And my words shoot to kill when I'm mad
//  I have a lot of regret about that

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

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
        vector<T> odd;
        vector<T> even;
        int n;

        graph(int _n) : n(_n) {
            g.resize(n);
            odd.assign(n,inf);
            even.assign(n,inf);
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
        using graph<T>::odd;
        using graph<T>::even;
        

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

        void calc_dist(int from){
            queue<pair<int,T>> q;
            q.push({0,0});
            while(!q.empty()){
                pair<int,int> t = q.front();
                q.pop();
                if(t.second&1){
                    if(t.second >= odd[t.first]){
                        continue;
                    }
                    odd[t.first] = t.second;
                }else{
                    if(t.second >= even[t.first]){
                        continue;
                    }
                    even[t.first] = t.second;
                }
                for(auto i:g[t.first]){
                    int t2 = edges[i].from;
                    if(t2 == t.first){
                        t2 = edges[i].to;
                    }
                    q.push({t2,t.second+1});
                }
            }
        }
        
};




int n,m,l;

void solve(){
    cin >> n >> m >> l;
    undigraph<ll> G(n);
    multiset<ll> ms;
    ll u,v;
    ll sum = 0;
    ll mn = inf;

    for(int i = 0; i < l; i++){
        cin >> u;
        ms.insert(u);
        sum += u;
        if (u&1){
            mn = min(mn,u);
        }
    }

    for(int i = 0 ; i < m; i++){
        cin >> u >> v;
        u--; v--;
        G.add(u,v);
    }
    G.calc_dist(0);
    dbg(G.odd);
    dbg(G.even);

    ll even = sum;
    ll odd = max(0ll,sum-mn);
    if(sum&1){
        swap(odd,even);
    }

    vector<ll> o = G.odd;
    vector<ll> e = G.even;

    for(int i = 0; i < n; i++){
        if(o[i]<=odd || e[i]<=even){
            cout << "1";
        }else{
            cout << "0";
        }
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2109/problem/D
