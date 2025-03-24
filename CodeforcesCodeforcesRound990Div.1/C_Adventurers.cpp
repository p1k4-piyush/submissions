//  I didn't have it in myself to go with grace
//  And you're the hero flying around, saving face
//  And if I'm dead to you, why are you at the wake?


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
vector<pair<int,int>> arr;

void solve(){
    cin >> n;
    arr.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
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



// time-limit: 3000
// problem-url: https://codeforces.com/contest/2046/problem/C

// time-limit: 3000
// problem-url: https://codeforces.com/contest/2046/problem/C
