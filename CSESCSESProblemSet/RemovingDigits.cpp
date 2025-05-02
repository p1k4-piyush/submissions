//  Time, mystical time
//  Cuttin' me open then healing me fine
//  Were there clues I didn't see?

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
vector<ll> arr;

set<int> digits(ll t){
    set<int> s;
    while(t > 0){
        s.insert(t%10);
        t /= 10;
    }
    return s;
}

void solve(){
    cin >> n;
    arr.assign(n+1,INF);
    arr[0] = 0;
    for(int i = 0; i <= n; i++){
        for(auto j:digits(i)){
            arr[i] = min(arr[i],arr[i-j]+1);
        }
    }
     
    cout << arr[n] << nl;
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1637
