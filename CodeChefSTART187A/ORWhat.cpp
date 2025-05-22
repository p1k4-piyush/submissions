//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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

ll n,x;

void solve(){
    cin >> n >> x;
    vector<ll> ans(n,-1);
    vector<bool> used(n,1);

    for(ll i = 1; i <= n; i++){
        ll t = i^x;
        dbg(t);
        if((t <= n) && (t >= 1) && (used[t-1]) && ((i|t) == x)){
            ans[i-1] = t;
            used[t-1] = 0;
        }
    }

    int cur = 0;
    for(int i = 0; i < n; i++){
        if(used[i]){
            while(cur < n && ans[cur] != -1){
                cur++;
            }
            ans[cur] = i+1;
            cur++;
        }
    }
    for(auto i:ans){
        cout << i << " ";
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


// time-limit: 1000
// problem-url: https://www.codechef.com/START187A/problems/PORX
