//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I

#include <bits/stdc++.h>
using namespace std;

typedef __int64_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,m;
vector<vector<pair<int,ll>>> G;
ll ans = INF;

void dfs(int u, int p, ll cur,vector<bool> visited){
    visited[u] = 1;
    if (u == n-1){
        ans = min(ans,cur); return;
    }
    for (auto i:G[u]){
        if (!visited[i.first]){
            dfs(i.first,u,cur^i.second,visited);
        }
    }
}
void solve(){
    cin >> n >> m;
    G.resize(n);
    ll u,v,w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    vector<bool> visited(n,0);
    dfs(0,0,0,visited);
    
    
    cout << ans << nl;
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
// problem-url: https://atcoder.jp/contests/abc396/tasks/abc396_d
