//  To live for the hope it 
//  Cancel plans just incase you'd call
//  And say you meet me behind the mall
//  So much for summer love and saying, "Us"
//  'Cause you weren't mine to lose

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

int a,b;
vector<vector<int>> dp;
const int MAX_N = 505;

void solve(){
    cin >> a >> b;
    
    cout << dp[a][b] << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    dp.assign(MAX_N,vector<int>(MAX_N,1e6));
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
            }

        }
    }


    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1744
