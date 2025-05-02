//  Even on my worst day, did I deserve, babe
//  All the hell you gave me?
//  'Cause I loved you, swear I loved you
//  'Til my dying day

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

//	https://github.com/the-tourist/algo/
//	https://github.com/p1k4-piyush/templates/


int n;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int i = 0;
    ll ans = 0;
    // if (arr[n-1]>arr[n-2]){
    //     arr.push_back(arr[n-1]+1);
    // }
    // if (arr[n-1]<arr[n-2]){
    //     arr.push_back(arr[n-1]-1);
    // }
    vector<ll> v;
    while(i < n-1){
        int s = i;
        if(arr[i]>arr[i+1]){
            while(i < n-1 && arr[i]>arr[i+1]){
                i++;
            }
        }else if(arr[i]<arr[i+1]){
            while(i < n-1 && arr[i]<arr[i+1]){
                i++;
            }
        }
        dbg(i-s);
        v.push_back(i-s+1);
        // ans += (i-s)*(i-s-1)/2;
        // dbg(ans);
        // i++;
    }
    
    for(int j = 0; j < v.size()-1; j++){
        ans += (v[j]+v[j+1]-(ll)3)*(v[j]+v[j+1]-(ll)2)/(ll)2;
        ans -= (v[j]-(ll)1)*(v[j]-(ll)2)/(ll)2;
        ans -= (v[j+1]-(ll)1)*(v[j+1]-(ll)2)/(ll)2;
    }

    for(int j = 0; j < v.size(); j++){
        ans += (v[j]-(ll)1)*(v[j])/(ll)2;
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
// problem-url: https://www.codechef.com/START179B/problems/FRMN
