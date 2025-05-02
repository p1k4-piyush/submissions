//  And they called off the circus
//  Burned the disco down
//  When they sent home the horses
//  And the rodeo clowns

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

int n;

void solve(){
    cin >> n;
    if(n%2 == 0){
        cout << -1 << nl; return;
    }
    cout << n << " ";    
    for(int i = 1; i < n; i++){
        cout << i << " ";
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
// problem-url: https://codeforces.com/contest/2084/problem/A
