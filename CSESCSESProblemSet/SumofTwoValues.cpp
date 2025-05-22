//  Don't want no other shade of blue
//  But you
//  No other sadness in the world would do

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

int n,x;
vector<int> arr;

void solve(){
    cin >> n >> x;
    arr.assign(n,0);
    map<int,vector<int>> mp;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i+1);
    }

    sort(arr.begin(),arr.end());

    for(int i = 0; i < n; i++){
        auto it = lower_bound(arr.begin()+i+1,arr.end(),x-arr[i]);
        if (it == arr.end()){
            continue;
        }
        if (*it + arr[i] == x){
            if(*it == arr[i]){
                cout << mp[arr[i]][0] << " " << mp[arr[i]][1] << nl;
            }else{
                cout << mp[arr[i]][0] << " " << mp[*it][0] << nl;
            }
            return;
        }
    }
    
    
    cout << "IMPOSSIBLE" << nl;
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
// problem-url: https://cses.fi/problemset/task/1640
