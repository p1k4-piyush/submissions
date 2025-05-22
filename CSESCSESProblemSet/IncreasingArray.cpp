//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I

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

void solve(){
    cin >> n;
    ll prev = 0;
    ll ans = 0;
    ll t;
    
    for(ll i = 0; i < n; i++){
        cin >> t;
        if (t < prev){
            ans += prev-t;
        }
        prev = max(prev,t);
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
// problem-url: https://cses.fi/problemset/task/1094
