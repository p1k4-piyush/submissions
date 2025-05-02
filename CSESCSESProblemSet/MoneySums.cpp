//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I

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
    
    vector<bool> dp(1e5+10,0);
    dp[0] = 1;

    for(int j = 0; j < n; j++){
        for(int i = 1e5+9; i >= 0; i--){
            if(i < arr[j]) continue;
            dp[i] = dp[i]|dp[i-arr[j]];
        }
    }

    vector<int> ans;
    for(int i = 1; i < 1e5+9; i++){
        if(dp[i])   ans.push_back(i);
    }

    cout << ans.size() << nl;
    for(auto i:ans){
        cout << i << " ";
    } 
    
    cout << nl;
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
// problem-url: https://cses.fi/problemset/task/1745
