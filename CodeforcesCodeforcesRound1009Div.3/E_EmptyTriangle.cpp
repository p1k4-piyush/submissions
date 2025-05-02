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


mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

uniform_int_distribution<int> dist(0,2);

void solve(){
    cin >> n;
    arr.resize(n);
    iota(all(arr),1);
    dbg(arr);
    
    shuffle(all(arr),rng);
    int ans[3];
    for(int i = 0; i < 3; i++){
        ans[i] = arr[i];
    }

    while(true){
        cout << "? " << ans[0] << " " << ans[1] << " " << ans[2] << nl; cout.flush();
        int it; cin >> it;
        if (it==0) break;
        int tt = dist(rng);
        ans[tt]=it; 
    }

    cout << "! " << ans[0] << " " << ans[1] << " " << ans[2] << nl; cout.flush();
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2074/problem/E
