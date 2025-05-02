//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all


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
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);

    bool c = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] == 0) c = 1;
    }
    if (!c){
        cout << "1" << nl;
        cout << "1 " << n << nl;
        return;
    }
    if (arr[0]!= 0){
        cout << "2" << nl;
        cout << "2 " << n << nl;
        cout << "1 2" << nl;
        return;
    }
    if (arr[n-1]!=0){
        cout << "2" << nl;
        cout << "1 " << n-1 << nl;
        cout << "1 2" << nl;
        return;
    }    
    cout << "3" << nl;
    cout << "3 " << n << nl;
    cout << "1 2" << nl;
    cout << "1 2" << nl;
    
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
// problem-url: https://codeforces.com/contest/2085/problem/B

// time-limit: 1000
// problem-url: https://codeforces.com/contest/2085/problem/B
