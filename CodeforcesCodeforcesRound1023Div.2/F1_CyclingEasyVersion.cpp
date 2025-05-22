//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<ll> dp(n+1,INF);
    dp[n] = 0;
    for (ll r = n; r >= 1; r--){
        for(ll l = 0; l < r; l++){
            dp[l] = min(dp[l],dp[r]+(r-l-1)+ll(arr[r-1])*(r-l));
            if(l+1 != r){
                dp[l+1] = min(dp[l+1],dp[r]+2*(r-l-1)+ll(arr[l])*(r-l-1));
            }
        }
    }
    
    
    cout << dp[0] << nl;
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
// problem-url: https://codeforces.com/contest/2107/problem/F1
