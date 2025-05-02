//  I knew I'd curse you for the longest time
//  Chasin' shadows in the grocery line
//  I knew you'd miss me once the thrill expired
//  And you'd be standin' in my front porch light

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
    ll x,m;
    cin >> x >> m;
    ll ans = 0;
    ll t;
    FOR(i,min(x,m)){
        t = (i+1ll)^x;
        if (t%(i+1ll) == 0) ans++;
    }
	
    ll lo = 2ll, hi = m/x,mid,y;    
    while (hi >= lo){
        mid = (hi+lo+1)/2;
        y = (mid*x)^x;  
        if (y <= m){
            lo = mid+1;
        }else{
            hi = mid-1;
        }

    }
    for(ll i = max(2ll,lo);i<lo+10;i++){
        if (((x*i)^x) <= m) ans++;
    }

    cout << ans+lo-2 << nl;
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
// problem-url: https://codeforces.com/contest/2039/problem/C2
