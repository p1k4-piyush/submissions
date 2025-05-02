//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

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

const int MAX_N = 200+100;
ll arr[MAX_N][MAX_N];

void solve(){
	ll n,m,k; cin >> n >> m >> k;
	
    for(ll i = 0ll; i < n; i++){
        for(ll j = 0ll; j < m; j++){
            cin >> arr[i][j];
        }
	}
    ll ans = INF; 
	for (int shift  = 0; i < m; i++)

    cout << nl;
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



// time-limit: 2500
// problem-url: https://codeforces.com/contest/2049/problem/D
