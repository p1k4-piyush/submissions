//  But we were something, don't you think so?
//  Roaring 20s, tossing pennies in the pool
//  And if my wishes came true
//  It would've been you

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,n) for (ll i = 0; i < n; ++i)
#define FOR2(i,n) for (ll i = n-1; i >= 0 ; --i)

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

vector<vector<ll>> G;
vector<ll> depth,d,par;

void dfs(ll v, ll p){
    if (depth[v] == 1ll) d[v] = 1ll;
    if (depth[v] > 1ll) d[v] = d[par[p]] + 2ll*(ll)G[p].size();
    par[v] = p;

    for (ll i:G[v]){
        if (i == p) continue;
        depth[i] = depth[v] + 1ll;
        dfs(i,v);
    }
}

void solve(){
	ll n,q; cin >> n >> q;
	depth.assign(n,0ll);
    d.assign(n,0ll);
    par.assign(n,0ll);
    G.assign(n,vector<ll>());
    ll u,v;
    for(ll i = 0ll; i < n-1ll; i++){
    	cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
	}
    
    dfs(0ll,0ll);

    for(ll i = 0ll; i < q; i++){
        cin >> u >> v; 
        u--;
        ll ans = d[u];
        vector<ll> t;
        while(u != 0ll && par[u] != 0ll){
            t.push_back((ll)G[par[u]].size());
            u = par[par[u]];
        }
        sort(t.begin(),t.end(),greater<ll>());
        for(ll j = 0ll; j < min(v,(ll)t.size()); j++){
            ans -= 2ll*(t[j]-1ll);
        }
        cout << ans << nl;
    }
	

	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2040/problem/E
