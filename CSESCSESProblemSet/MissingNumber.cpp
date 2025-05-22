//  I never learned to read your mind
//  I couldn't turn things around
//  'Cause you never gave a warning sign
//  All this time

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
    ll t,tt;
    t = 0;
    for(int i = 0; i < n-1; i++){
        cin >> tt;
        t ^= tt;
        t ^= (i+1);
    }
    t ^= n;
    
    
    cout << t << nl;
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
// problem-url: https://cses.fi/problemset/task/1083
