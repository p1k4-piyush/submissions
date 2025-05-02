//  You had to kill me, but it killed you just the same
//  Cursing my name, wishing I stayed
//  You turned into your worst fears

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
#define int ll
const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int N = ceil(log2(INF));
ll x,y;
ll xx,yy;
vector<vector<ll>> dp(N,vector<ll>(N,INF));

void solve(){
    cin >> x >> y;
    ll ans = INF;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            xx = x>>i;
            yy = y>>j;
            if(xx == yy) ans = min(ans,dp[i][j]);
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
    dp[0][0] = 0;
    for (int x = 1; x < N; x++){
        ll cst = 1ll<<x;
        vector<vector<ll>> tmp = dp;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i>=x){
                    dp[i][j] = min(dp[i][j],tmp[i-x][j]+cst);
                }
                if (j>=x){
                    dp[i][j] = min(dp[i][j],tmp[i][j-x]+cst);
                }
            }
        }
    }
    dbg(dp);
    while(t--){
        solve();
    }
    return 0;
}



// time-limit: 3500
// problem-url: https://codeforces.com/contest/2075/problem/D
