//  Second, third, and hundreth chances
//  Balancin' on breaking branches
//  Those eyes add insult to injury

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n,m,t;

void solve(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            if ((i+j)&1){
                cout << t + (t&1) << " ";
            }else{
                cout << t + ((t+1)&1) << " ";
            }
        }
        cout << nl;
    }
    
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
// problem-url: https://codeforces.com/problemset/problem/1438/C
