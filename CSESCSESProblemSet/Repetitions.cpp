//  Stood on the cliffside
//  Screaming, "Give me a reason"
//  Your faithless love's the only hoax
//  I believe in

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
string s;
void solve(){
    cin >> s;
    n = s.size();
    int ans = 1, cur = 1;
    char t= s[0];
    for(int i = 1; i < n; i++){
        if (s[i]==t){
            cur++;
        }else{
            t = s[i];
            cur = 1;
        }
        ans = max(ans,cur);
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
// problem-url: https://cses.fi/problemset/task/1069
