//  I just wanted you to know
//  That this is me trying
//  I just wanted you to know
//  That this is me trying

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

void solve(){
    cin >> n;
    char prev = '0';
    int ans = 0;
    char t;

    for(int i = 0; i < n; i++){
        cin >> t;
        if(prev != t){
            prev = t;
            ans++;
        }
    }
    
    if(ans == 2){
        ans--;
    }
    if (ans > 2){
        ans -= 2;
    }
    
    cout << ans + n << nl;
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


// time-limit: 1500
// problem-url: https://codeforces.com/contest/2103/problem/B
