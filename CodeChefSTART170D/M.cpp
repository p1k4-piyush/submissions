//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I

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

const int MAX_N = 2e5+100;
ll arr[MAX_N];

void solve(){
	ll n,x; cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    ll ans = 0;
    sort(arr,arr+n,greater<ll>());
    for(int i = 0; i < n; i++){
        ans = max(ans,arr[i]+x*i);
    }
    cout << ans << nl;
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



// time-limit: 1000
// problem-url: https://www.codechef.com/START170D/problems/MINBOTTLES
