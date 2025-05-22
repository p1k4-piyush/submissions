//  You're not my homeland anymore
//  So what am I defending now?
//  You were my town
//  Now I'm in exile, seein' you out

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

int r,x;

void solve(){
    cin >> r >> x;
    if (x == 1){
        if (r >= 1600 && r <=2999){
            cout << "Yes";
        }else{
            cout << "No";
        }
    }else{
        if (r >= 1200 && r <=2399){
            cout << "Yes";
        }else{
            cout << "No";
        }
    }
    
    
    cout << nl;
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
// problem-url: https://atcoder.jp/contests/abc405/tasks/abc405_a
