//  I was walking home on broken cobblestones
//  Just thinking of you when she pulled up
//  Like a figment of my worst intentions
//  She said, "James, get it, let's drive"

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

ll n,x,t;
multiset<ll> st;

void solve(){
    cin >> n >> x;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        st.insert(t);
    }

    ll ans = 0;
    while(!st.empty()){
        auto it = st.begin();
        ll tt = *it;
        st.erase(it);
        it = st.upper_bound(x-tt);
        if(it != st.begin()){
            it--;
            tt += *it;
            st.erase(it);
        }
        ans++;
        dbg(st);
    }
    
    
    cout << ans << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1090
