//  Remember when I pulled up and said, "Get in the car"
//  And then canceled my plans, just in case you'd call
//  Back when I was livin' for the hope of it all
//  "Meet me behind the mall"

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
    
    while(n > 1){
        cout << n << " ";
        if (n&1){
            n = 3*n +1;
        }else{
            n /= 2;
        }
    }

    
    cout << 1 << nl;
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
// problem-url: https://cses.fi/problemset/task/1068
