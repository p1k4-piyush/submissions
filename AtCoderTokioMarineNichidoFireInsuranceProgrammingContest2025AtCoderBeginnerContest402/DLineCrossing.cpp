//  What do sing on your drive home?
//  Do you see my face in the neighbor's lawn?
//  Does she smile?
//  Or does she mouth, "F*** you forever"

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

int n,m;
map<int,int> mp;

void solve(){
    cin >> n >> m;
    int l,r;

    for(int i = 0; i < m; i++){
        cin >> l >> r;
        mp[(r+l)%n]++;
    }
    dbg(mp);
    ll ans = 0;
    for(auto i:mp){
        ans += i.second*(m-i.second);
    }
    dbg(ans);
    ans /= 2;
    
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


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc402/tasks/abc402_d
