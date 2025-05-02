//  We gather stones, never knowing what they'll mean
//  Some to throw, some to make a diamond ring

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n,k;
multiset<int> s;

void solve(){
    cin >> n >> k;
    s.clear();
    int t,tt,ttt;

    for(int i = 0; i < n; i++){
        cin >> t;
        s.insert(t);
    }

    int ans = 0;
    while(!s.empty()){
        dbg(s);
        ans++;
        t = *s.begin();
        dbg(t);
        s.erase(s.begin());
        if(s.empty())   break;
        if(t >= k) continue;
        auto p = s.lower_bound(k-t);
        if (p != s.begin()){
            p = prev(p);
            dbg(*p);
            t += *p;
            s.erase(p);
        }
        if(s.empty())   break;
        if (t >= k) continue;
        p = prev(s.end());
        dbg(*p);
        s.erase(p);
    }
    
    
    cout << ans-1 << nl;
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


// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2068/C
