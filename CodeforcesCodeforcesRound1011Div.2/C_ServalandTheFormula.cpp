//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet


#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
ll x,y;

void solve(){
    cin >> x >> y;
    if (x == y){
        cout << "-1" << nl; return;
    }
    if (y>x) swap(x,y);
    ll x2 = x;
    ll t = 0;
    while(x2>0){
        t++; x2>>=1;
    }
    dbg(t);
    cout << (1ll<<t)-x;
    
    dbg(1ll<<t);
    dbg((1ll<<t)-x+y);
    
    cout << nl;
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2085/problem/C

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2085/problem/C
