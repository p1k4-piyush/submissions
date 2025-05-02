//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(1e9);
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n,m;

void solve(){
    cin >> n >> m;
    ll x = 0;
    ll t = 1;
    for(ll i = 0; i <= m; i++){
        x+=t;
        if (x > INF){
            cout << "inf"; return;
        }
        t *= n;
    }
    
    cout << x << nl;
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
// problem-url: https://atcoder.jp/contests/abc400/tasks/abc400_b
