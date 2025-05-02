//  'Cause I knew you
//  Steppin' on the last train
//  Marked me like a bloodstain, I

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
int n,c;
vector<int> arr;

void solve(){
    cin >> n >> c;
    arr.assign(5,0);
    char t;

    for(int i = 0; i < n; i++){
        cin >> t;
        arr[t-'A']++;
    }
    ll ans = INF;
    for(int i = 0; i < (1<<6)-1; i++){
        int t = i;
        ll temp = 0;
        ll tt = 0;
        for(int j = 0; j < 6; j++){
            bool c1 = t&1;
            if (c1){
                temp += c;
            }else{
                tt += arr[j];
            }
            t >>= 1;
        }
        temp += (tt)*(tt+1ll)/2ll;
        ans = min(ans,temp);
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



// time-limit: 1000
// problem-url: https://www.codechef.com/START176B/problems/LSU
