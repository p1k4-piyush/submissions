//  Time, mystical time
//  Cuttin' me open then healing me fine
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

ll n;

void solve(){
    cin >> n;
    for(ll i = 1;i<=n;i++){
        cout << i*i*(i*i-1ll)/2ll - 4ll*(i-1ll)*(i-2ll) << nl;
    }

    
    
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
// problem-url: https://cses.fi/problemset/task/1072
