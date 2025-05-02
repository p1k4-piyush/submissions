//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n;
ll l,r;
vector<int> arr;
vector<int> pre;
void solve(){
    cin >> n >> l >> r;
    arr.resize(n);
    pre.resize(n+1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if (!(n&1)){
        n++;
        int c = 0;
        for(int i = 0; i < n/2; i++){
            c ^= arr[i];
        }
        arr.push_back(c);
    }
    
    for (int i = 0; i < n; i++){
        pre[i] = arr[i];
        if (i == 0) continue;
        pre[i] ^= pre[i-1];
    }

    auto ans = [&](ll x,auto && ans){
        if (x == 0){
            return 0;
        }
        if (x <= n){
            return pre[x-1];
        }
        if (x <= 2*n+1){
            return pre[x/2 - 1];
        }
        if ((x/2)&1){
            return pre[n-1];
        }
        return pre[n-1]^ans(x/2,ans);
    };

    if (l <= n){
        cout << arr[l-1] << nl;
        return;
    }
    
    
    cout << ans(l,ans) << nl;
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
// problem-url: https://codeforces.com/contest/2071/problem/D1
