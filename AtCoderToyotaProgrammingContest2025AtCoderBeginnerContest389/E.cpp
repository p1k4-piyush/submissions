//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all

#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const ll MAX_N = 2e5+100;
ll arr[MAX_N];
ll n;
ll m;
ll t2 = 0;
ll ans = 0;
bool check(ll x){
    ll t = 0;
    for(ll i = 0; i < n; i++){
        ll cnt = (x+arr[i])/(arr[i]*2ll);
        t += cnt*cnt*arr[i];
        if (t > m) return false;
    }
    return true;
}

void solve(){
    long long unsigned int n1,m1;
	cin >> n1;
	cin >> m1;
    n = n1; m = m1;

	for(ll i = 0; i < n; i++){
		cin >> n1; arr[i]=n1;
	}
    
    ll lo = 0, hi = INF; ll mid;
    ll ttt;
    while(hi >= lo){
        mid = (hi+lo)/2;
        if (check(mid)){
            lo = mid+1;
            ttt = mid;
        }else{
            hi = mid-1;
        }
    }
    ll cnt;
    ll x = ttt;
    for(ll i = 0; i < n; i++){
        cnt = (x+arr[i])/(arr[i]*2ll);
        ans += cnt;
        t2 += (cnt*cnt*arr[i]);
    }
    cout << (long long unsigned int)(ans + (m-t2)/(x+1ll)) << nl;
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
// problem-url: https://atcoder.jp/contests/abc389/tasks/abc389_e
