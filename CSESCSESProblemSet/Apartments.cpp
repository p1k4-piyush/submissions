//  The wedding was charming, if a little gauche
//  There's only so far as new money goes
//  They picked out a home and called it "Holiday House"

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

ll n,m,k;
vector<ll> arr;
vector<ll> arr2;

void solve(){
    cin >> n >> m >> k;
    arr.assign(n,0);
    arr2.assign(m,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());

    ll i = 0,j = 0;
    ll ans = 0;
    
    while(i < n && j < m){
        if((arr2[j] + k >= arr[i]) && (arr2[j]-k <= arr[i])){
            ans++;
            i++;
            j++;
        }else if(arr2[j] + k > arr[i]){
            i++;
        }else{
            j++;
        }
    }
    
    cout << ans << nl;
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
// problem-url: https://cses.fi/problemset/task/1084
