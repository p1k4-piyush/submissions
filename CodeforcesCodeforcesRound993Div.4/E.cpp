//  I never learned to read your mind
//  I couldn't turn things around
//  'Cause you never gave a warning sign
//  All this time

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
    ll k,l1,l2,r1,r2;	
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    ll n = 0;
    ll cur = 1;
    while(cur <= r2){
        ll x = min(r1,r2/cur)-max((l2+cur-1)/cur,l1)+1;
        if (x > 0){
            ans += x;
        }
        cur *= k;
    }

    cout << ans << nl;
    cout.flush();
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
// problem-url: https://codeforces.com/contest/2044/problem/E
