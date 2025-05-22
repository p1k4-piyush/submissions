//  But I'm a fire, and I'll keep my brittle heart warm
//  If your cascade ocean waves blues come
//  All these people think love's for show
//  But I would die for you in secret

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
vector<vector<int>> arr;

void solve(){
    cin >> n;
    arr.assign(n,vector<int>(n,-1));
    
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int x = (n-1)/2, y = (n-1)/2;
    int cur = 1;
    int tt = 1;
    int dir = 0;
    arr[x][y] = 0;

    while (cur < n * n) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < tt && cur < n * n; ++j) {
                x += dirs[dir].first;
                y += dirs[dir].second;
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    arr[x][y] = cur++;
                }
            }
            dir = (dir + 1) % 4;
        }
        ++tt;
    }

    for(auto i:arr){
        for(auto j:i){
            cout << j << " ";
        }
        cout << nl;
    }
    
    
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
// problem-url: https://codeforces.com/contest/2102/problem/C
