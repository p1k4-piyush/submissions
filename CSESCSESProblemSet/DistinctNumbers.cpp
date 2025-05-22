//  Now I breathe flames each time I talk
//  My cannons all firin' at your yatch
//  They say, "Move on", but you know, I won't

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
map<int,int> mp;

void solve(){
    cin >> n;
    int t;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        mp[t] = 0;
    }
    cout << mp.size();
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
// problem-url: https://cses.fi/problemset/task/1621
