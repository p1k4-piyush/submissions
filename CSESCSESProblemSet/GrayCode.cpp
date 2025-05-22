//  I never learned to read your mind
//  I couldn't turn things around
//  'Cause you never gave a warning sign
//  All this time

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

vector<int> arr;

vector<string> s;
void f(int x){
    if (x == 1){
        s.push_back("0");
        s.push_back("1");
        return;
    }
    f(x-1);

    vector<string> rev = s;
    reverse(rev.begin(),rev.end());

    int n = s.size();
    for(int i = 0; i < n; i++){
        s.push_back("1" + rev[i]);
        s[i] = "0" + s[i];
    }
}


void solve(){
    int n;
    cin >> n;
    
    f(n);
    for(auto i:s){
        cout << i << nl;
    }
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
// problem-url: https://cses.fi/problemset/task/2205
