//  Time, mystical time
//  Cuttin' me open then healing me fine
//  Were there clues I didn't see?

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

vector<pair<int,int>> ans;

void f(int n,int from, int to, int aux){
    if (n == 0) return;
    f(n-1,from,aux,to);
    ans.push_back({from,to});
    f(n-1,aux,to,from);
}


void solve(){
    int n;
    cin >> n;
    
    f(n,1,3,2);
    cout << ans.size() << nl;
    for(auto i:ans){
        cout << i.first << " " << i.second << nl;
    }
    
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
// problem-url: https://cses.fi/problemset/task/2165
