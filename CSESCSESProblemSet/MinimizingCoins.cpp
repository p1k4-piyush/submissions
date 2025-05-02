//  Stood on the cliffside
//  Screaming, "Give me a reason"
//  Your faithless love's the only hoax
//  I believe in

#include <bits/stdc++.h>
using namespace std;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n,x;
vector<int> arr;
vector<int> dp;

void solve(){
    cin >> n >> x;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    dp.assign(x+1,1e8);
    dp[0] = 0;

    for(auto j:arr){
        for(int i = 0; i <= x; i++){
            if (j > i) continue;
            dp[i] = min(dp[i],dp[i-j]+1);
        }
    }

    if(dp[x]==1e8){
        cout << "-1" << nl; return;
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
// problem-url: https://cses.fi/problemset/task/1634
