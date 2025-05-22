//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(1e18);
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n,k;
vector<bool> check;
vector<ll> arr;

ll kadane(vector<ll> &v){
    ll ans = 0;
    ll cur = 0;
    for(auto i:v){
        cur += i;
        cur = max(cur,0ll);
        ans = max(ans,cur);
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    check.assign(n,0);
    arr.assign(n,0);
    
    int c = -1;
    char tt;
    for(int i = 0; i < n; i++){
        cin >> tt;
        check[i]=(tt-'0');
    }

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(!check[i]){
            arr[i] = -INF;
            c = i;
        }
    }

    ll mx = kadane(arr);
    if(mx > k || ((c==-1) && (mx != k))){
        cout << "No" << nl; return;
    }
    cout << "Yes" << nl;
    if (c != -1){
        ll L = 0;
        ll cur = 0;
        for(int i = c+1; i < n; i++){
            cur += arr[i];
            L = max(L,cur);
        }
        ll R = 0;
        cur = 0;
        for(int i = c-1; i >= 0; i--){
            if (arr[i] == -INF){
                break;
            }
            cur += arr[i];
            R = max(R,cur);
        }
        arr[c] = k - L - R;
    }
    for (auto i:arr){
        cout << i << " ";
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2107/problem/C
