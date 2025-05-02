//  Even on my worst day, did I deserve, babe
//  All the hell you gave me?
//  'Cause I loved you, swear I loved you
//  'Til my dying day

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

ll n,k,x;
vector<ll> arr;
vector<ll> pre;

void solve(){
    cin >> n >> k >> x;
    arr.assign(n,0);
    pre.assign(n+1,0);

    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        pre[i+1] = pre[i]+arr[i];
    }
    pre.pop_back(); 
    ll ans = 0;
    ll t = k*sum;
    for(ll i = 0; i < k; i++){
        ll tt = t- x - i*sum;
        if (tt < 0) break;
        int c = upper_bound(pre.begin(),pre.end(),tt)-pre.begin();
        ans += c;
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
// problem-url: https://codeforces.com/contest/2086/problem/B
