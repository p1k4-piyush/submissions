//  Take the words for what they are
//  A dwindiling, mercurial high
//  A drug that only worked 
//  The first few hundred times

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

int n;
vector<int> par;

void solve(){
    cin >> n;
    
    par.assign(n,0);

    ll ans = 0;
    int tt;
    for(int i = 0; i < n; i++){
        cin >> tt;
        par[i] = tt-1;
    }
    int q;
    for(int t = 0; t < n; t++){
        cin >> q;
        q--;
        while(par[q]!=-1){
            ans++;
            int q1 = par[q];
            par[q] = -1;
            q = q1;
        }
        cout << ans << " ";
    }

    
    cout << nl;
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2086/problem/C
