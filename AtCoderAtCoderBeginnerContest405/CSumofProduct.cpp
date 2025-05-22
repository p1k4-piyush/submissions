//  I knew you
//  Tried to change the ending
//  Peter losing Wendy, I

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
    ll ans = 0; 
    ll sum = 0;
    ll t;
    for(int i = 0; i < n; i++){
        cin >> t;
        ans += t;
        sum += t*t;
    }
    ans *= ans;
    ans -= sum;
    ans /=2 ;
    
    
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
// problem-url: https://atcoder.jp/contests/abc405/tasks/abc405_c
