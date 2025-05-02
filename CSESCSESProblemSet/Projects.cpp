//  We were something, don't you think so?
//  Rosé flowing with your chosen family
//  And it would've been sweet
//  If it could've been me

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

ll n;
vector<tuple<ll,ll,ll>> arr;

void solve(){
    cin >> n;
    arr.assign(n,{0,0,0});
    
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
        get<1>(arr[i])++;
        mp[get<0>(arr[i])] = 1;
        mp[get<1>(arr[i])] = 1;
    }

    int idx = 1;
    for(auto &i:mp){
        i.second = idx++;
    }
    for(auto &i:arr){
        get<0>(i) = mp[get<0>(i)];
        get<1>(i) = mp[get<1>(i)];
    }

    sort(arr.begin(),arr.end(),[&](tuple<ll,ll,ll> i, tuple<ll,ll,ll> j){ return get<1>(i)<get<1>(j);}); 
    dbg(arr);

    vector<ll> dp(idx,0);
    int cur = 1;
    for(auto i:arr){
        while(cur <= get<1>(i)){
            dp[cur] = max(dp[cur],dp[cur-1]);
            cur++;
        }
        dp[get<1>(i)] = max(dp[get<1>(i)],dp[get<0>(i)]+get<2>(i));
    }
    dbg(dp);

    cout << dp[idx-1] << nl;
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
// problem-url: https://cses.fi/problemset/task/1140
