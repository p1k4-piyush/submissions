//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

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

const int MAX_N = 2e5+100;

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    
    if(n==k){
        int ans = 1;
        for(int i = 1;i < n; i+=2){
            if (arr[i]==ans){
                ans++;
            }else{
                break;
            }
        }
        cout << ans << nl; return;
    }

    for(int i = 1; i <= n-k+1; i++){
        if(arr[i]!=1){
            cout << "1" << nl; return;
        }
    }
    cout << "2" << nl;
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
// problem-url: https://codeforces.com/contest/2059/problem/B
