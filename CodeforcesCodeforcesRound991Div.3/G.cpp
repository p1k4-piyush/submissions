//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

vector<vector<ll>> G;
vector<pair<ll,ll>> dp;

void dfs(ll v, ll p){
    dp[v].first = (ll)G[v].size();
    ll m1 = -1ll, m2 = -1ll;
    for (auto i:G[v]){
        if (i == p) continue;

        dfs(i,v);
        dp[v].first = max(dp[v].first, dp[i].first + (ll)G[v].size() - 2ll);

        m2 = max(m2,dp[i].first);
        if (m2 > m1) swap(m2,m1);
    }

    dp[v].second = dp[v].first;
    if (m2 != -1) dp[v].second = m1+m2+(ll)G[v].size() - 4ll;
}

void solve(){
	int n; cin >> n;
    G.assign(n,vector<ll>());
    dp.assign(n,{0,0});
    int u,v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
	}

    dfs(0,0);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans,max(dp[i].first,dp[i].second));
    }

	cout << ans << nl;
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
// problem-url: https://codeforces.com/contest/2050/problem/G
