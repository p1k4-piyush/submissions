//  I was so ahead of the curve, the curve became a sphere
//  Fell behind all my classmates, and I ended up here
//  Pouring out my heart to a stranger
//  But I didn't pour the whiskey

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

int n;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n+100,0);
    int t;

    for(int i = 0; i < n; i++){
        cin >> t; arr[t]++;
    }
    int ans = 0;
    for(auto i:arr){
        if(i) ans++;
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


// time-limit: 1000
// problem-url: https://codeforces.com/contest/2103/problem/A
