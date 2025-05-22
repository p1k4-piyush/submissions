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

int n;
vector<int> arr;

void solve(){
    cin >> n;
    
    int x; cin >> x;
    x = abs(x);
    int c = 0;
    int t;
    for(int i = 0; i < n-1; i++){
        cin >> t; t = abs(t);
        if (t>x){
            c++;
        }
    }
    if (c >= (n-1)/2){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
    
    cout << nl;
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
// problem-url: https://codeforces.com/contest/2102/problem/B
