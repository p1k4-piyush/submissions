//  Salt air, and the rust on your door
//  I never needed anything more
//  Whispers of "Are you sure?"
//  "Never have I have before"

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

ll l,r,k;
vector<ll> zeb;
vector<vector<vector<vector<ll>>>> dp;

void f(vector<int> &L){
    int n = L.size();
    dp.assign(40,vector<vector<vector<ll>>>(100,vector<vector<ll>>(2,vector<ll>(2,0))));
    dp[0][0][1][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3*n+2; j++){
            for(int k = 0; k < 5; k++){
                if (j+k >= 3*n+2) break;
                if (L[i] == k){
                    if(k == 4){
                        dp[i+1][j+k][1][1] += dp[i][j][1][0];
                        dp[i+1][j+k][0][1] += dp[i][j][0][0];
                        continue;
                    }
                    if(k == 0){
                        dp[i+1][j+k][1][1] += dp[i][j][1][1];
                        dp[i+1][j+k][0][1] += dp[i][j][0][1];

                    }
                    dp[i+1][j+k][1][0] += dp[i][j][1][0];
                    dp[i+1][j+k][0][0] += dp[i][j][0][0];
                }else if(L[i] > k){
                    if(k == 0){
                        dp[i+1][j+k][0][1] += dp[i][j][0][1] + dp[i][j][1][1];
                    }
                    dp[i+1][j+k][0][0] += dp[i][j][0][0] + dp[i][j][1][0];
                }else{
                    if(k == 4){
                        dp[i+1][j+k][0][1] += dp[i][j][0][0];
                        continue;
                    }
                    if (k == 0){
                        dp[i+1][j+k][0][1] += dp[i][j][0][0];
                    }
                    dp[i+1][j+k][0][0] += dp[i][j][0][0];
                }
            }
        }
    }
}

void solve(){
    cin >> l >> r >> k;
    l--;

    if(k > 90){
        cout << 0 << nl; return;
    }
    
    vector<int> L,R;

    for(int i = zeb.size()-1; i>=0; i--){
        L.push_back(l/zeb[i]);
        l = l%zeb[i];
    }
    dbg(L);

    for(int i = zeb.size()-1; i>=0; i--){
        R.push_back(r/zeb[i]);
        r = r%zeb[i];
    }
    dbg(R);

    f(L);
    // dbg(dp);
    ll ans = dp[zeb.size()][k][0][0]+dp[zeb.size()][k][0][1]+dp[zeb.size()][k][1][0]+dp[zeb.size()][k][1][1];
    dbg(ans);

    f(R);
    ll ans2 = dp[zeb.size()][k][0][0]+dp[zeb.size()][k][0][1]+dp[zeb.size()][k][1][0]+dp[zeb.size()][k][1][1];
    dbg(ans2);

    cout << ans2 - ans << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    ll cur = 0;
    while(cur < INF){
        cur <<= 2;
        cur++;
        zeb.push_back(cur);
    }
    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2086/problem/E
