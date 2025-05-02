//  A friend to all is a friend to none
//  Chase two girls, lose the one
//  When you are young, they assume you know nothin'


#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n;

void solve(){
    cin >> n;
    
    for(int i = 0; i < (n-1)/2; i++){
        cout << "-";
    }
    
    cout << "=";
    if ((n%2 == 0)) cout << "=";

    for(int i = 0; i < (n-1)/2; i++){
        cout << "-";
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



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_a

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_a
