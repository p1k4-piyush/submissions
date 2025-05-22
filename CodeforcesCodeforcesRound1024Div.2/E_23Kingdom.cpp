//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green

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

int n;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int l = 0, r = n-1;
    int cur = 1;
    while(r > l){
        if(min(arr[l],arr[r]) >= cur){
            arr[l]-=cur;
            arr[r]-=cur;
            cur++;
            ans += r-l;
        }
        arr[l+1] += arr[l];
        arr[r-1] += arr[r];
        l++;r--;
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


// time-limit: 4000
// problem-url: https://codeforces.com/contest/2102/problem/E
