//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green


#include <bits/stdc++.h>
using namespace std;

typedef __int128_t ll;
#define all(x) (x).begin(), (x).end()
#define int __int128_t

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

int n;

void solve(){
    __int64_t n1; cin >> n1;
    n = n1;
    int t = cbrt((long double)n)+1000;
    for (int i = 1; i < t; i++){
        if (i == 276544){
            dbg("e");
        }
        int d = 3*i*(4*n-i*i*i);
        if (i == 276544) dbg(i*i*i);

        if (d < 0) continue;
        int d2 = sqrtl(d);
        if (d2*d2 != d){
            continue;
        }
        if (i == 276544){
            dbg("e");
        }
        int p = d2 - 3*i*i;
        int q = 6*i;
        if (p < 0 || p%q != 0)continue;
        if (i == 276544){
            dbg("e");
        }

        int y = p/q;
        int x = y+i;
        if (y <= 0) continue;
        if (i == 276544){
            dbg("e");
        }

        if (x*x*x - y*y*y == n){
            cout << (__int64_t(x)) << " " << (__int64_t(y)); return;
        }
    }

        
    
    cout << "-1";
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
// problem-url: https://atcoder.jp/contests/abc397/tasks/abc397_d


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc397/tasks/abc397_d
