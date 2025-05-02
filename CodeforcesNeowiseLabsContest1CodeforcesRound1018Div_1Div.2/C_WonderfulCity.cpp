//  I guess you never know, never know
//  And if you wanted me, you really should have showed
//  And if you never bleed, you're never gonna grow
//  And it's alright now

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
vector<vector<ll>> arr;
vector<ll> a,b;

void solve(){
    cin >> n;
    arr.assign(n,vector<ll>(n,0));
    a.assign(n,0);
    b.assign(n,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<int> dp(n-1,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            int d = arr[i][j+1] - arr[i][j];
            if(d == 0){
                dp[j] |= 1;
            }else if(d == 1){
                dp[j] |= 2;
            }else if(d == -1){
                dp[j] |= 4;
            }
        }
    }
    ll p1 = 0, p2 = b[0];
    for(int i = 0; i < n-1; i++){
        ll n1 = INF; 
        ll n2 = INF;
        if(p1 < INF){
            if(!(dp[i]&1)){
                n1 = min(n1,p1);
            }
            if(!(dp[i]&4)){
                n2 = min(n2,p1+b[i+1]);
            }
        }
        if(p2 < INF){
            if(!(dp[i]&2)){
                n1 = min(n1,p2);
            }
            if(!(dp[i]&1)){
                n2 = min(n2,p2+b[i+1]);
            }
        }
        p1 = n1;
        p2 = n2;
    }
    ll ans = min(p1,p2);

    dp.assign(n-1,0);
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            int d = arr[i+1][j] - arr[i][j];
            if(d == 0){
                dp[i] |= 1;
            }else if(d == 1){
                dp[i] |= 2;
            }else if(d == -1){
                dp[i] |= 4;
            }
        }
    }
    p1 = 0, p2 = a[0];
    for(int i = 0; i < n-1; i++){
        ll n1 = INF; 
        ll n2 = INF;
        if(p1 < INF){
            if(!(dp[i]&1)){
                n1 = min(n1,p1);
            }
            if(!(dp[i]&4)){
                n2 = min(n2,p1+a[i+1]);
            }
        }
        if(p2 < INF){
            if(!(dp[i]&2)){
                n1 = min(n1,p2);
            }
            if(!(dp[i]&1)){
                n2 = min(n2,p2+a[i+1]);
            }
        }
        p1 = n1;
        p2 = n2;
    }
    ans += min(p1,p2);
    if(ans >= INF){
        cout << "-1" << nl; return;
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2096/problem/C
