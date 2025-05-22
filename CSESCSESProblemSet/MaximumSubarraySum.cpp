//  Their parties were tasteful if a little loud
//  The doctor had told him to settle down
//  It must have been her faunt his heart gave out

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

int n;

void solve(){
    cin >> n;
    
    ll t;
    ll cur = 0;
    ll ans = -inf;
    for(int i = 0; i < n; i++){
        cin >> t;
        cur = max(cur+t,t);
        ans = max(ans,cur);
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
// problem-url: https://cses.fi/problemset/task/1643
