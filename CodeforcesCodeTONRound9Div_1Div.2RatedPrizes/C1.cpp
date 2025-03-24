//  Bill was the heir to Standard Oil name and money
//  And the town said, "How did a middle-class divorcée do it?

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


void solve(){
	ll x,m; cin >> x >> m;
    ll ans=0;	
    FOR(y,min(x*2,m)+1){
        if (y == 0 || y == x){
            continue;
        }
        ll i = x^y;
    	ans += ((x%i == 0)||(y%i == 0));
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
// problem-url: https://codeforces.com/contest/2039/problem/C1
