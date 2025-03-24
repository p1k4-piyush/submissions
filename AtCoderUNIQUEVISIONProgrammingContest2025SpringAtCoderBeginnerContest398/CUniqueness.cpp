//  You had to kill me, but it killed you just the same
//  Cursing my name, wishing I stayed
//  You turned into your worst fears


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
    arr.assign(n,{0,0});
     
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(all(arr));

    if (n == 1){
        cout << arr[0].second; return;
    }

    if (arr[n-1].first!=arr[n-2].first){
        cout << arr[n-1].second; return;
    }

    for (int i = n-2; i > 0; i--){
        if (arr[i].first!=arr[i-1].first && arr[i].first!=arr[i+1].first){
            cout << arr[i].second; return;
        }
    }
    
    if (arr[0].first!=arr[1].first){
        cout << arr[0].second; return;
    }
    
    
    cout << "-1";
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
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_c

