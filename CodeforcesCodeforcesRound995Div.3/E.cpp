//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all

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

const int MAX_N = 2e5+100;
int a[MAX_N];
int b[MAX_N];

void solve(){
	int n,k; cin >> n >> k;
	set<int> s;
    FOR(i,n){
    	cin >> a[i];
        s.insert(a[i]);
	}

    FOR(i,n){
        cin >> b[i];
        s.insert(b[i]);
    }

    sort(a,a+n); sort(b,b+n);
    ll ans = 0;

    for(auto i:s){
        ll tot = n - (lower_bound(b,b+n,i) - b);
        ll pos = n - (lower_bound(a,a+n,i) - a);
        ll neg = tot - pos;
        if (neg <= k){
            ans = max(ans, i*tot);
        }
        dbg(ans);
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
// problem-url: https://codeforces.com/contest/2051/problem/E
