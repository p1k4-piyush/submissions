//  And you can aim for my heart, go for blood
//  And you would still miss me in your bones
//  And I still talk to you
//  And when you can't sleep at night (you hear my stolen lullabies)

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

const int MAX_N = 1e5+100;
ll a[MAX_N];
ll b[11];
ll tt[1024];
ll c[MAX_N][11];

void solve(){
	int n,m,k; cin >> n >> m >> k;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i]; 
        ans+= a[i];
	}
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m+1; j++){
            c[i][j] = INF;
        }
    }

    for(int i = 0; i < (1<<m); i++){
        ll t = (1ll<<32);
        t--;
        for(int j = 0; j < m; j++){
            if(i >> j & 1){
                t &= b[j];
            }
        }
        tt[i] = t;
    }
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < (1<<m); j++){
            int t = __builtin_popcount(j);
            c[i][t] = min(c[i][t],tt[j]&a[i]);
            // cout << t << " ";
            // cout << c[i][t] << " ";
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m+1; j++){
    //         cout << c[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    
    vector<ll> arr;
    
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            arr.push_back(c[i][j-1]-c[i][j]);
        }
    }
    sort(arr.begin(),arr.end(),greater<ll>());
    for(int i = 0; i < k; i++){
        ans -= arr[i];
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2061/problem/E
