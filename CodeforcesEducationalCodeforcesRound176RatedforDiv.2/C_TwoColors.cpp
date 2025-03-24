//  I knew you
//  Hand under my sweatshirt
//  Baby, kiss it better, I

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,m;
vector<int> arr;
vector<ll> pre;
void solve(){
    cin >> n >> m;
    arr.assign(m,0);
    
    for(int i = 0; i < m; i++){
        cin >> arr[i];
        if (arr[i] == n) arr[i]--;
    }
    sort(all(arr));
    pre.assign(m+1,0);
    for (int i = 1; i <= m; i++){
        pre[i] = pre[i-1]+arr[i-1];
    }
    ll ans = 0;
    for (int i = 0; i < m; i++){
        int it = lower_bound(arr.begin()+i+1,arr.end(),n-arr[i])-arr.begin();
        dbg(it);
        dbg(pre[m]-pre[it]);
        ans += 2ll*(pre[m]-pre[it] - ((ll)(m-it))*((ll)(n-arr[i]-1ll)));
        dbg(ans);
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2075/problem/C
