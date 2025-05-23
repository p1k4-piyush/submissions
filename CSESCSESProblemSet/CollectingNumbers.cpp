//  And when I felt like I was an old cardigan
//  Under someone's bed
//  You put me on and said I was your favorite

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
vector<bool> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    int t;
    int ans = 0;

    for(int i = 0; i < n; i++){
        cin >> t;
        t--;
        arr[t] = 1;
        if(t){
            if(!arr[t-1]){
                ans++;
            }
        }else{
            ans++;
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
// problem-url: https://cses.fi/problemset/task/2216
