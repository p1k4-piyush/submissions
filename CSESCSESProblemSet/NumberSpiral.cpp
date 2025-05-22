//  Time, curious time 
//  Gave me no compasses, gave me no signs
//  Were there clues I didn't see?

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

ll x,y;

void solve(){
    cin >> y >> x;
    ll ans,tt;
    if (y > x){
        ans = (y-1)*(y-1);
        tt = 0;
        if(y%2){
            tt = x;
        }else{
            tt = 2*y-x;
        }
    }else{
        ans = (x-1)*(x-1);
        tt = 0;
        if (x%2){
            tt = 2*x-y;
        }else{
            tt = y;
        }
    }
    
    cout << ans + tt << nl;
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1071
