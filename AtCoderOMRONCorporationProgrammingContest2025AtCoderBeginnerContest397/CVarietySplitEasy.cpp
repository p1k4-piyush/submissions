//  We gather stones, never knowing what they'll mean
//  Some to throw, some to make a diamond ring

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
int n;
vector<int> arr;
vector<int> pre;
vector<int> suf;

void solve(){
    cin >> n;
    arr.assign(n,0);
    pre.assign(n,0);
    suf.assign(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    int temp = 0;
    map<int,int> mp1;
    for (int i = 0; i < n; i++){
        if (i == 0){
            mp1[arr[0]] = 1;
            pre[0] = 1;
            continue;
        }

        if (mp1.count(arr[i]) == 0){
            mp1[arr[i]] = 1;
            pre[i]++;
        }
        pre[i] += pre[i-1];
    }

    map<int,int> mp2;
    for (int i = n-1; i >= 0; i--){
        if (i == n-1){
            mp2[arr[n-1]] = 1;
            suf[n-1] = 1;
            continue;
        }

        if (mp2.count(arr[i]) == 0){
            mp2[arr[i]] = 1;
            suf[i]++;
        }
        suf[i] += suf[i+1];
    }
    
    for (int i = 0; i < n-1; i++){
        ans = max(ans,pre[i]+suf[i+1]);
    }
    ans = max(ans,pre[n-1]);
    
    

    
    
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



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc397/tasks/abc397_c
