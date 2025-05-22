//  And they called off the circus
//  Burned the disco down
//  When they sent home the horses
//  And the rodeo clowns

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

int n,m,p,q;

void solve(){
    cin >> n >> m >> p >> q;
    
    if (n%p){
        cout << "YES";
    }else{
        if (n/p*q == m){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }
    
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


// time-limit: 1000
// problem-url: https://codeforces.com/contest/2102/problem/A
