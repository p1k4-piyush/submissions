//  Betty, I'm here on your doorstep
//  And I planned it out for weeks now but
//  It's finally sinking in
//  Betty, right now is the last time 
//  I can dream about what happens when you see my face again
//  The only thing I want to do
//  Is make it up to you

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
set<int> s;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }
    int k = 2;
    while(!s.empty()){
        set<int> rem;
        for(auto i:s){
            k--;
            if(k) continue;
            k = 2;
            rem.insert(i);
            cout << i << " ";
        }
        for(auto i:rem){
            s.erase(i);
        }
    }
     
    cout << nl;
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
// problem-url: https://cses.fi/problemset/task/2162
