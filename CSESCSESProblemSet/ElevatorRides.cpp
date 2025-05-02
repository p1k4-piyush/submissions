//  Bill was the heir to Standard Oil name and money
//  And the town said, "How did a middle-class divorcée do it?

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
vector<ll> arr;

void solve(){
    cin >> n >> x;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    ll m = (1<<n);
    vector<pair<int,ll>> dp(m,{1e6,0});
    dp[0] = {1,0};

    for(ll i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ll p = (ll(1)<<j);
            if(i&p){
                int o = dp[i^(1<<j)].first;
                ll o2 = dp[i^(1<<j)].second;

                if(o2+arr[j] > x){
                    o++;
                    o2 = min(o2,arr[j]);
                }else{
                    o2 += arr[j];
                }

                dp[i] = min(dp[i],{o,o2});
            }
        }
    }

    dbg(dp);

    cout << dp[m-1].first << nl;
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
// problem-url: https://cses.fi/problemset/task/1653
