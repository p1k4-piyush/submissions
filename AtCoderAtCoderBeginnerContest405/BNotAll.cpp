//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

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

int n , m;
vector<int> arr;

void solve(){
    cin >> n >> m;
    arr.assign(m,0);
    int t; 
    int c = 0;
    int tt = -1;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t > m || arr[t-1]){
            continue;
        }
        arr[t-1] = 1;
        c++;
        if(c == m){
            tt = i;
            break;
        }
    }
    if (tt == -1){
        cout << "0" << nl;
        return;
    }
    
    
    cout << n - tt << nl;
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
// problem-url: https://atcoder.jp/contests/abc405/tasks/abc405_b
