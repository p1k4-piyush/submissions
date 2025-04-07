//  We were something, don't you think so?
//  Rosé flowing with your chosen family
//  And it would've been sweet
//  If it could've been me

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

ll n,m,k;

void solve(){
    cin >> n >> m >> k;
    ll lo = k, hi = n;
    while(hi > lo){
        ll mid = (hi+lo+1)/2;
        if(n/mid >= m+1){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    ll t = 0;
    while(t < n){
        cout << (t%lo) << " ";
        t++;
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
// problem-url: https://codeforces.com/contest/2084/problem/D
