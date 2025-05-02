//  I'm not your problem anymore
//  So what am I defending now?
//  You were my crown
//  Now I'm in exile, seein' you out

#include <bits/stdc++.h>
using namespace std;

typedef __int128_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
ll n,m;

void solve(){
    __int64_t n1,m1;
    cin >> n1 >> m1;
    n = n1; m = m1;
    
    vector<ll> arr;
    if (n > m){
        cout << "-1" << nl; return;
    }

    
    arr.push_back(n);

    ll pos = 1;
    while(pos<=m){
        
        while (n & pos){
            pos<<=1;
        }
        if(n + pos <=m) arr.push_back(n+pos);
        pos<<=1;

        // n += pos;
    }
    
    if (arr.size()<2){
        cout << "-1";
    }else{
        cout << arr.size() << nl;
        for(auto i:arr) cout << __int64_t(i) << " ";
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
// problem-url: https://www.codechef.com/START176B/problems/SAME_AND
