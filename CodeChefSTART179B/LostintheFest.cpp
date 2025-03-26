//  And when I felt like I was an old cardigan
//  Under someone's bed
//  You put me on and said I was your favorite

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

int n;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int t = arr[n-1];

    for(int i = 1; i < n; i++){
        arr[i] = max(arr[i],arr[i-1]);
    }

    for (int i = n-2; i >= 0; i--){
        if (t>arr[i]){
            cout << n-i-2 << nl;
            return;
        }
    }
    
    
    cout << n-1 << nl;
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
// problem-url: https://www.codechef.com/START179B/problems/MDGT
