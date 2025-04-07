//  I didn't have it in myself to go with grace
//  And you're the hero flying around, saving face
//  And if I'm dead to you, why are you at the wake?

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
vector<int> arr;

void solve(){
    cin >> n;
    if(400%n){
        cout << -1 << nl; return;
    }
    
    
    cout << (400/n) << nl;
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
// problem-url: https://atcoder.jp/contests/abc400/tasks/abc400_a
