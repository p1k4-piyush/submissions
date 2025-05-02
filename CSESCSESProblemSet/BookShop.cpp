//  Don't want no other shade of blue
//  But you
//  No other sadness in the world would do

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

int n,x;
vector<int> s,h;
vector<ll> dp;

void solve(){
    cin >> n >> x;
    s.assign(n,0);
    h.assign(n,0);
    dp.assign(x+1,0);

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = x; j >= 0; j--){
            if(h[i] > j) break;
            dp[j] = max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
    
    
    cout << dp[x] << nl;
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1158
