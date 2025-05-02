//  Time, wonderous time 
//  Gave me the blues and then purple pink skies
//  And it's cool baby with me

#include <bits/stdc++.h>
#include <numeric>
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

    ll sum = accumulate(arr.begin(),arr.end(),ll(0));

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int l = n-1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l==r){
                dp[l][r] = arr[l];
            }else{
                dp[l][r] = max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
            }
        }
    }

    cout << (sum+dp[0][n-1])/2 << nl;
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
// problem-url: https://cses.fi/problemset/task/1097
