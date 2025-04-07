//  Time, curious time 
//  Gave me no compasses, gave me no signs
//  Were there clues I didn't see?

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n;

void solve(){
    cin >> n;
    ll ans = 0;
    n >>= 1;
    ans = sqrtl(n);
    n >>= 1;
    ans += sqrtl(n);
    
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


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc400/tasks/abc400_c
