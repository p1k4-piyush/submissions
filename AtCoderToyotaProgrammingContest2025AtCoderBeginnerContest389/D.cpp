//  I think I've seen this film before
//  And I didn't like the ending 
//  You're not my homeland anymore
//  So what am I defending now?

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
	ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i < n; i++){
        ans += (ll)(sqrtl((long double)n*n - (long double)i*i - (long double)i - (long double)(0.25))-(long double)(0.5));
    }
    ans = 4*ans + 4*(n-1)+1;
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
// problem-url: https://atcoder.jp/contests/abc389/tasks/abc389_d
