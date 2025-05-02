//  And they called off the circus
//  Burned the disco down
//  When they sent home the horses
//  And the rodeo clowns

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
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll mn_i = min_element(arr.begin(),arr.end())-arr.begin();
    ll mn = arr[mn_i];
    ll g = 0;
    dbg(mn);
    for(int i = 0; i < n; i++){
        if(i == mn_i){
            continue;
        }
        if (arr[i]%mn == 0){
            g = gcd(g,arr[i]);
        }
        dbg(g);
    }
    
    if (g == mn){
        cout << "Yes";
    }else{
        cout << "No";
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
// problem-url: https://codeforces.com/contest/2084/problem/B
