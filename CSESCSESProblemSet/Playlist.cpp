//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I

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
    map<int,int> mp;
    int ans = 0;
    int t;
    int l = 0;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(mp.contains(t) && mp[t] >= l){
            l = mp[t]+1;
        }
        ans = max(ans,i-l+1);
            
        mp[t] = i;
    }
    
    
    cout << ans << nl;
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
// problem-url: https://cses.fi/problemset/task/1141
