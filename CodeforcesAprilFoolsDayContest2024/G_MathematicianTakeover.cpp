//  And it's hard to be at a party when I feel like an open wound
//  It's hard to be anywhere these days when all I want is you
//  You're a flashback in a film reel on the one screen in my town

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

long double n;

void solve(){
    cin >> n;
    
    cout << log2(n) << nl;
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
// problem-url: https://codeforces.com/contest/1952/problem/G
