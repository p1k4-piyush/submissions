//  Sequin smile, black lipstick
//  Sensual politics
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
vector<ll> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<vector<ll>> dp(n,vector<ll>(n,-INF));

    for(int len = 1; len <= n; len++){
        for(int l = 0; l < n; l++){
            int r = (l+len-1)%n;
            if(len <= 2){
                dp[l][r] = 0; continue;
            }
            if(len == 3){
                dp[l][r] = max(ll(0),arr[l]*arr[(l+1)%n]*arr[r]); continue;
            }
            for(int i = l; i != r; i = (i+1)%n){
                dp[l][r] = max(dp[l][r],dp[l][i]+dp[(i+1)%n][r]);
                if (i == l) continue;
                ll t = (arr[l]*arr[r]*arr[i]);
                if (i != (l+1)%n) t += dp[(l+1)%n][(i-1+n)%n];
                if (i != (r+n-1)%n) t += dp[(i+1)%n][(r+n-1)%n];
                dp[l][r] = max(dp[l][r],t);
            } 
        }
    }
    ll ans = 0;
    for(auto i:dp){
        for(auto j:i){
            ans = max(ans,j);
        }
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


// time-limit: 4000
// problem-url: https://codeforces.com/problemset/problem/2074/G
