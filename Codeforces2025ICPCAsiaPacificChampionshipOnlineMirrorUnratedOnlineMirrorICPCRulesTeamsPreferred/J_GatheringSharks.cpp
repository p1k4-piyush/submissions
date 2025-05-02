//  Vintage tee, brand new phone
//  High heels on cobblestones
//  When you are young, they assume you know nothing

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    int t;

    for(int i = 0; i < n; i++){
        cin >> t; t--; arr[t] = i;
    }
    
    vector<vector<ll>> dp(n,vector<ll>(n+1,INF));

    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
        dp[i][i+1] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int l = 0; l < n; l++){
            int r = l+len;
            if (r > n) break;
            for(int p = l; p < r; p++){
                dp[l][r] = min(dp[l][r],dp[l][p+1] + dp[p][r-1] + abs(arr[p]-arr[r-1]));
            }
        }
    }
    dbg(dp);
    
    cout << dp[0][n] << nl;
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


// time-limit: 3000
