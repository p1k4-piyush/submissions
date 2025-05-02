//  But we were something, don't you think so?
//  Roaring 20s, tossing pennies in the pool
//  And if my wishes came true
//  It would've been you

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

int n,m;
vector<vector<int>> arr;
vector<vector<int>> arr2;
void solve(){
    cin >> n >> m;
    arr.assign(n,vector<int>(m,0));
    arr2.assign(n,vector<int>(m,0));

    char t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            arr[i][j]=(t-'0');
        }
    }
    
    
    for (int i = 0; i < n; i++){
        bool c = 1;
        for (int j = 0; j < m;j++){
            if(c && arr[i][j]){
                arr2[i][j]=1;
            }
            c &= arr[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        bool c = 1;
        for (int j = 0; j < n;j++){
            if(c && arr[j][i]){
                arr2[j][i]=1;
            }
            c &= arr[j][i];
        }
    }
    
    
    cout << ((arr2==arr)?"YES":"NO") << nl;
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
// problem-url: https://codeforces.com/contest/2090/problem/B
