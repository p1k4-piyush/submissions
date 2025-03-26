//  But we were something, don't you think so?
//  Roaring 20s, tossing pennies in the pool
//  And if my wishes came true
//  It would've been you

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
    
    int t;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (i==0){
            t = arr[0];
        }
        if (arr[i] == t){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }
    
    ll c0 = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]){
            c0--;
        }else{
            c0++;
        }
        if (c0 < 0){
            ans++;
        }else{
            break;
        }
    }
    ll ans1 = 0;
    c0 = 0;
    for(int i = 0; i < ans; i++){
        if (arr[i] == 1){
            if (c0 == 0){
                ans1++;
            }else{
                c0--;
            }
        }else{
            c0++;
        }
    }
    cout << ans1 << nl;
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
// problem-url: https://www.codechef.com/START179B/problems/SETMJR
