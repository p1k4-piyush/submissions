#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif



mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());


int n;
vector<pair<int,int>> ans;
void solve(){
    cout << 10000 << nl;
    uniform_int_distribution<ll> dist(0,1);
    for(int i = 0; i < 10000; i++){
        cout << dist(rng) << " ";
    }
    cout << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cout << "1" << nl;
    while(t--){
        solve();
    }
    return 0;
}

