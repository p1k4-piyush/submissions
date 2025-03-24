//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I

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

void solve(){
    
    int x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    
    int ans = 0;
    ans += min(x,a);
    if (a > x){
        a -= x; x = 0;
    }else{
        a = 0; x = 0;
    }
    ans += min(a,y);
    if (a > y){
        a -= y; y = 0;
    }else{
        y -= a; a = 0;
    }
    ans += min(a,z);
    if(a > z){
        a -= z; z = 0;
    }else{
        z -= a; a = 0;
    }
    
    ans += min(b,y);
    if (b > y){
        b -= y; y = 0;
    }else{
        y = 0; b = 0;
    }
    ans += min(b,z);
    if(b > z){
        b -= z; z = 0;
    }else{
        z -= b; b = 0;
    }

    ans += min(c,z);
    
    

    
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
// problem-url: https://www.codechef.com/START176B/problems/XLSL
