//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    bool c = 0;
    for (int i = 2; i < n; i++){
        if (arr[i] == arr[i-1] && arr[i] == arr[i-2]){
            c = 1; break;
        }
    }
    
    
    cout << (c?"Yes":"No") << nl;
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
// problem-url: https://atcoder.jp/contests/abc396/tasks/abc396_a
