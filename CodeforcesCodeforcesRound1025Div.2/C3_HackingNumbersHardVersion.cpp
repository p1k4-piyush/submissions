//  Bad was the blood on the song in the cab
//  On your first trip to LA
//  You ate at my favorite spot for dinner

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

int n,x;

void solve(){
    cin >> n;
    cout << "mul 999999999" << nl;
    cout.flush();
    cin >> x;
    cout << "digit" << nl;
    cout.flush();
    cin >> x;
    if(n!=81){
        cout << "add " << n-81 << nl;
        cout.flush();
        cin >> x;
    }
    cout << "!" << nl;
    cout.flush();
    cin >> x;
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
// problem-url: https://codeforces.com/contest/2109/problem/C3
