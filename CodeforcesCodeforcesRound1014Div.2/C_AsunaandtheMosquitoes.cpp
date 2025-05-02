//  I knew you
//  Your heartbeat on the High Line
//  Once in 20 lifetimes, I

#include <algorithm>
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
vector<ll> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);

    ll o = -1;
    ll e = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if((arr[i])&1){
            o++;
        }else{
            e++;
        }
    }
    if((o == (ll)-1) || (e == (ll)0)){
        cout << *max_element(arr.begin(),arr.end()) << nl; return;
    }
    
    
    cout << accumulate(arr.begin(),arr.end(),(ll)0)-o << nl;
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
// problem-url: https://codeforces.com/contest/2092/problem/C
