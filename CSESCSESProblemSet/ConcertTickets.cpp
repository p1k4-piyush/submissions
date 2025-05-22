//  We were something, don't you think so?
//  Rosé flowing with your chosen family
//  And it would've been sweet
//  If it could've been me

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

ll n,m,t;
multiset<ll> st;

void solve(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        st.insert(t);
    }

    for(int i = 0; i < m; i++){
        cin >> t;
        auto it = st.upper_bound(t);
        if (it == st.begin()){
            cout << "-1" << nl; continue;
        }
        it--;
        cout << *it << nl;
        st.erase(it);
    }
    
    
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1091
