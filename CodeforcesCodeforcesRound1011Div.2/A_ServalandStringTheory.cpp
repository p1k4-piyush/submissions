//  I knew I'd curse you for the longest time
//  Chasin' shadows in the grocery line
//  I knew you'd miss me once the thrill expired
//  And you'd be standin' in my front porch light


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
int n,k;
string arr;

void solve(){
    cin >> n >> k;
    cin >> arr;
    string arr2 = arr;
    reverse(all(arr2));
    if (k == 0){
        cout << ((arr<arr2)?"YES":"NO") << nl; return;
    }
    bool c = 0;
    for(int i = 1; i < n; i++){
        if (arr[i] != arr[i-1]){
            c = 1; break;
        }
    }
    
    cout << ((c)?"YES":"NO") << nl; return;
    
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
// problem-url: https://codeforces.com/contest/2085/problem/0

// time-limit: 1000
// problem-url: https://codeforces.com/contest/2085/problem/0
