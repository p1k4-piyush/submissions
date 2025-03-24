//  We always walked a very thin line
//  You didn't even hear me out
//  You never gave a warning sign
//  All this time

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
vector<int> arr;

void solve(){
    cin >> n;
    int t,tt;
    stack<int> s;
    for(int i = 0; i < 105; i++) s.push(0);
    for(int i = 0; i < n; i++){
        cin >> t;
        if (t == 2){
            cout << s.top() << nl; s.pop();
        }else{
            cin >> t;
            s.push(t);
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



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc396/tasks/abc396_b
