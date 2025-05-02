//  But I can see us lost in the memory
//  August slipped away into a moment of time
//  'Cause it was never mine

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

int n,m;
string a,b;

void solve(){
    cin >> a >> b;
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,1e6));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i > 0)   dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            if(j > 0)   dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            if(i > 0 && j > 0){
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
            }
        }
    }

    cout << dp[n][m] << nl;
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
// problem-url: https://cses.fi/problemset/task/1639
