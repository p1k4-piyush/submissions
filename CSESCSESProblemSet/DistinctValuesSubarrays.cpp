//  Salt air, and the rust on your door
//  I never needed anything more
//  Whispers of "Are you sure?"
//  "Never have I have before"

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n;
vector<ll> arr;

void solve(){
    cin >> n;
    arr.assign(n,n);
    map<ll,ll> mp;
    ll t;
    
    for(ll i = 0; i < n; i++){
        cin >> t;
        if(mp.contains(t)){
            arr[mp[t]] = i; 
        }
        mp[t] = i;
    }
    for(int i = n-2; i >= 0; i--){
        arr[i] = min(arr[i],arr[i+1]);
    }
    dbg(arr);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += arr[i]-i;
    }
    
    
    cout << ans << nl;
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
// problem-url: https://cses.fi/problemset/task/3420
