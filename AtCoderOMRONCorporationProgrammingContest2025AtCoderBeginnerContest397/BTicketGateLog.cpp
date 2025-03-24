//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n;
string s;

void solve(){
    cin >> s;
    n = s.size();
    int ii=0,o=0;
    int tt = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (s[i]=='i'){
            if (!(tt&1)){
                ans++;
                tt++;
            }
        }else{
            if (tt&1){
                tt++;ans++;
            }
        }
        tt++;
    }
    
    
    cout << ans+(n+ans&1) << nl;
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



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc397/tasks/abc397_b
