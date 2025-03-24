//  We gather stones, never knowing what they'll mean
//  Some to throw, some to make a diamond ring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 3e5+100;
int n;
ll arr[MAX_N];
ll tt[MAX_N];
ll pre[MAX_N];
ll pre3[MAX_N];
ll pre2[MAX_N];

pair<ll,ll> bs(ll x){
    ll lo =0, hi= n;
    ll mid;
    while(hi > lo+1){
        mid = (hi+lo)/2;
        if(tt[mid]>=x){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    return {hi-1,x-tt[lo]-1};
}

void solve(){
	cin >> n;
    
    for(int i = 1; i <= n; i++){
        tt[i] = tt[i-1]+n-i+1;
    }

	for(int i = 0; i < n; i++){
		cin >> arr[i+1];
	}

    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1]+arr[i];
    }
    pre2[n] = arr[n];
    for(int i = n-1; i > 0; i--){
        pre2[i] = pre2[i+1] + (n-i+1)*arr[i];
    }

    for(int i = 0; i < n; i++){
        pre3[i+1] = pre2[i+1] + pre3[i];
    }

    
    int q; cin >> q;
    int l,r;

    for(int i2 = 0; i2 < q; i2++){
        cin >> l >> r;
        ll l1,l2,r1,r2;
        tie(l1,l2) = bs(l);
        tie(r1,r2) = bs(r+1);
        dbg(make_pair(l,r));
        dbg(make_pair(l1,l2));
        dbg(make_pair(r1,r2));
        ll ans = 0;
        ans -= pre3[l1];
        ans += pre3[r1];
        dbg(ans);
        // ans += pre3[r1+r2-1];
        // ans -= pre2[1]-pre2[r1];
        // ans += pre[r1-1]*(n-r1-r2+1);
        // dbg(ans);
        // ans -= pre3[l1+l2-1];
        // ans += pre2[1]-pre2[l1];
        // ans -= pre[l1-1]*(n-l1-l2+1);
        cout << ans << nl;
    }
    
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



// time-limit: 4000
// problem-url: https://codeforces.com/contest/2026/problem/D
