#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;

void solve(){
    cin >> n;
    int x,y;
    int X=0,Y=0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        X ^= x;
        Y ^= (x+y);
    }

    cout << X << " " << Y-X << nl;
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
// problem-url: https://codeforces.com/contest/2096/problem/D
