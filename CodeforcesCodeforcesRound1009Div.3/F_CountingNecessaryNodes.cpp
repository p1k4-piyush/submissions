//  Take me to the lakes where all the poets went to die
//  I don't belong, and by beloved, neither do you
//  Those Windermere peaks look like a perfect place to cry
//  I'm setting off, but not without my muse

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

ll l1,r1,l2,r2;

void f(ll L, ll R, ll l, ll r, vector<pair<ll,ll>> &arr){
    if(L >= r||R <= l)  return;
    
    if (l <= L && r >= R){
        arr.push_back({L,R});
        return;
    }

    f(L,(L+R)/2,l,r,arr);
    f((L+R)/2,R,l,r,arr);
}

void solve(){
    cin >> l1 >> r1 >> l2 >> r2;
    vector<pair<ll,ll>> arr1,arr2;

    f(0,ll(1)<<32,l1,r1,arr1);
    f(0,ll(1)<<32,l2,r2,arr2);

    ll ans = 0;
    for(auto i:arr1){
        for(auto j:arr2){
            ll t1 = i.second-i.first;
            ll t2 = j.second-j.first;
            ans += max(t1,t2)/min(t1,t2);
        }
    }
    
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


// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/2074/F
