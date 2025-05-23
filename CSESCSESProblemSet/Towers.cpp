//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all

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

void solve(){
    cin >> n;
    int t;
    multiset<int> s;

    for(int i = 0; i < n; i++){
        cin >> t;
        auto it = s.upper_bound(t);
        if(it == s.end()){
            s.insert(t);
            continue;
        }
        s.erase(it);
        s.insert(t);
    }
    
    
    cout << s.size() << nl;
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
// problem-url: https://cses.fi/problemset/task/1073
