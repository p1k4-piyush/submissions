//  Our coming-of-age has come and gone
//  Suddenly the summer, it's clear
//  I never had the courage of my convictions
//  As long as danger is near

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

int n,k;
vector<int> l,r;

void solve(){
    cin >> n >> k;
    l.assign(n,0);
    r.assign(n,0);

    for(int i = 0; i < n; i++){
        cin >> l[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> r[i];
        if(l[i]>r[i]){
            swap(l[i],r[i]);
        }
        ans += r[i];
    }
    
    sort(l.begin(),l.end(),greater<int>());
    for(int i = 0; i < k-1; i++){
        ans += l[i];
    }
    
    cout << ans+1 << nl;
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
// problem-url: https://codeforces.com/contest/2096/problem/B
