//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
string s;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(0,0);
    
    cin >> s;
    set<int> st;
    // int t = 1;
    int mn = 1, mx = 1;
    arr.push_back(mx);
    for(auto i:s){
        if (i == '>'){
            mx++;
            arr.push_back(mx);
        }else{
            mn--;
            arr.push_back(mn);
        }
    }
    for(auto i:arr){
        cout << i-mn+1 << " ";
    }
    dbg(arr);
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
// problem-url: https://codeforces.com/contest/2096/problem/A
