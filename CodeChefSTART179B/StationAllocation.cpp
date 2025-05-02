
#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;


const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    ll sum = accumulate(arr.begin(), arr.end(), (ll)0);
    
    int q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        ll ans = INF;
 
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        if(pos < n){
            ll c1 = 0;
            ll c2 = max((ll)0, y - (sum - arr[pos]));
            ans = min(ans, c1+c2);
        }
        
        if(pos > 0){
            ll c1 = x - arr[pos - 1];
            ll c2 = max((ll)0, y - (sum - arr[pos - 1]));
            ans = min(ans, c1 + c2);
        }
        
        cout << ans << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
