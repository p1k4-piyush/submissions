//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all

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


void solve(){
	ll n,m; cin >> n >> m;
    ll ans = 4ll*m;
	ll x,y;
	for(ll i = 0ll; i < n; i++){
		cin >> x >> y;
        if (i == 0ll) continue;
        ans += 2ll*(x+y);
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



// time-limit: 1000
// problem-url: https://codeforces.com/contest/2056/problem/A
