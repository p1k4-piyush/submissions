//  And you can aim for my heart, go for blood
//  And you would still miss me in your bones
//  And I still talk to you
//  And when you can't sleep at night (you hear my stolen lullabies)

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

ll x,y,a;

void solve(){
    cin >> x >> y >> a;    
    ll t = a%(x+y);
    if (t >= x){
        cout << "YES";
    }else{
        cout << "NO";
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
// problem-url: https://codeforces.com/contest/2090/problem/A
