//  But I'm a fire, and I'll keep my brittle heart warm
//  If your cascade ocean waves blues come
//  All these people think love's for show
//  But I would die for you in secret

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

ll a,b;
void solve(){
    cin >> a >> b;
    if (a<b){
        swap(a,b);
    }
    if ((a+b)%3 || a > 2*b){
        cout << "NO";
    }else{
        cout << "YES";
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
// problem-url: https://cses.fi/problemset/task/1754
