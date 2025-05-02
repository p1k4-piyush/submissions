//  And it's hard to be at a party when I feel like an open wound
//  It's hard to be anywhere these days when all I want is you
//  You're a flashback in a film reel on the one screen in my town

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

int n;
string s;

void solve(){
    cin >> n;
    cin >> s;
    int ans = 0;
    int b = 0, g = 0;
    while((ans < n) && (b <= 2*g)){
        if (s[ans]=='B'){
            b++;
        }else{
            g++;
        }
        ans++;
    }
    
    cout << ans << nl;
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
// problem-url: https://www.codechef.com/START182B/problems/QBGI
