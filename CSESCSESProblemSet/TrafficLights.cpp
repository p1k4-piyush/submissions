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

ll x,n;
set<ll> s;
multiset<ll> ms;

void solve(){
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    ms.insert(x);
    ll t;

    for(int i = 0; i < n; i++){
        cin >> t;
        auto it = s.upper_bound(t);
        auto it2 = it; it2--;
        ms.erase(ms.find(*it-*it2));
        ms.insert(t-*it2);
        ms.insert(*it-t);
        s.insert(t);
        auto tt = ms.end();
        tt--;
        cout << *tt << " ";
    }
    
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
// problem-url: https://cses.fi/problemset/task/1163
