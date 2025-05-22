//  I knew you
//  Your heartbeat on the High Line
//  Once in 20 lifetimes, I

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n;

void solve(){
    cin >> n;
    
    ll sum = n*(n+1)/2;
    if(sum&1){
        cout << "NO" << nl; return;
    }
    vector<ll> v1,v2;
    ll s1 = 0;
    for(int i = n; i > 0; i--){
        if((sum/2 - s1)>=i){
            s1+=i;
            v1.push_back(i);
        }else{
            v2.push_back(i);
        }
    }

    cout << "YES" << nl << v1.size() << nl;
    for(auto i:v1){
        cout << i << " ";
    }
    cout << nl << v2.size() << nl;
    for(auto i:v2){
        cout << i << " ";
    }
    
    cout << nl;
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
// problem-url: https://cses.fi/problemset/task/1092
